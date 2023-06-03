#include "s21_string.h"

int s21_sprintf(char *str, const char *format, ...) {
  va_list arg = {0};
  va_start(arg, format);
  char *strStart = str;
  while (*format) {
    flag flags = {0};
    flags.accuracy = -1;
    if (*format == '%') {
      format++;
      flags_parser(&format, &flags, &arg);
      specs_parser(&flags, &arg, &str, format);
      if (*format == 'n') {
        int *per = va_arg(arg, int *);
        *per = str - strStart;
      }
    } else {
      *str = *format;
      str++;
    }
    format++;
  }
  *str = '\0';
  va_end(arg);
  return str - strStart;
}

void flags_parser(const char **format, flag *flags, va_list *arg) {
  while (**format == '-' || **format == '+' || **format == ' ' ||
         **format == '0' || **format == '#') {
    if (**format == '-') {
      flags->minus = 1;
    } else if (**format == '+') {
      flags->plus = 1;
    } else if (**format == ' ') {
      flags->space = 1;
    } else if (**format == '0') {
      flags->nullFlag = 1;
    } else if (**format == '#') {
      flags->hashFlag = 1;
    }
    *format = *format + 1;
  }

  if (**format == '*' || (**format >= 48 && **format <= 57)) {
    if (**format == '*') {
      flags->width = va_arg(*arg, int);
      *format = *format + 1;
    } else {
      char buf[10000] = {'\0'};
      for (int i = 0; **format >= 48 && **format <= 57;
           *format = *format + 1, i++) {
        buf[i] = **format;
      }
      flags->width = s21_atoi(buf);
    }
  }
  if (**format == '.') {
    *format = *format + 1;
    if (**format == '*') {
      flags->accuracy = va_arg(*arg, int);
      *format = *format + 1;
    } else {
      char buf[100] = {'\0'};
      for (int i = 0; **format >= 48 && **format <= 57;
           *format = *format + 1, i++) {
        buf[i] = **format;
      }
      flags->accuracy = buf[0] == '\0' ? 0 : s21_atoi(buf);
    }
  }
  if (**format == 'h' || **format == 'l' || **format == 'L') {
    flags->length = **format;
    *format += 1;
  }
}

void specs_parser(flag *flags, va_list *arg, char **str, const char *format) {
  if (*format == 'c' || *format == '%') {
    flags->spec = *format;
    charParse(flags, arg, str);
  } else if (*format == 'd' || *format == 'i') {
    flags->spec = *format;
    intParse(flags, arg, str);
  } else if (*format == 'f') {
    flags->spec = *format;
    doubleParse(flags, arg, str);
  } else if (*format == 'x' || *format == 'X' || *format == 'u' ||
             *format == 'o' || *format == 'p') {
    flags->spec = *format;
    unsignedParse(flags, arg, str);
  } else if (*format == 'e' || *format == 'E') {
    flags->spec = *format;
    mantissParse(flags, arg, str);
  } else if (*format == 'g' || *format == 'G') {
    flags->spec = *format;
    shortestViewNumParse(flags, arg, str);
  } else if (*format == 's') {
    flags->spec = *format;
    if (flags->length == 'l')
      w_stringParse(flags, arg, str);
    else
      stringParse(flags, arg, str);
  }
}
void intParse(flag *flags, va_list *arg, char **str) {
  int64_t d = va_arg(*arg, int64_t);
  if (flags->length == 'h') {
    d = (int16_t)d;
  } else if (flags->length == 0) {
    d = (int32_t)d;
  }
  int isPositive = (flags->plus && d >= 0) ? 1 : 0;
  int isSignNeed = (isPositive || (d < 0)) ? 1 : 0;
  int intLen = intLenInit(d);
  char toStrBuff[10000] = {'\0'};
  if (d == 0 && flags->accuracy == 0) {
    if (flags->width) {
      toStrBuff[0] = ' ';
      flags->space = 0;
    }
  } else {
    intToString(d, toStrBuff);
  }
  int spaceLength =
      spaceLengthInit(*flags, intLen, isSignNeed) - (isSignNeed ? 1 : 0);
  int nullLength = (flags->accuracy - intLen);
  formatToStr(*flags, str, toStrBuff, isPositive, spaceLength, nullLength);
}

void doubleParse(flag *flags, va_list *arg, char **str) {
  flags->accuracy == -1 ? flags->accuracy = 6 : flags->accuracy;
  long double f =
      (flags->length == 'L') ? va_arg(*arg, long double) : va_arg(*arg, double);
  int isPositive = ((f >= 0) && flags->plus) ? 1 : 0;
  int isNegative = (f < 0) ? 1 : 0;
  char toStrBuff[10000] = {'\0'};
  doubleToString(f, toStrBuff, *flags);
  int intLen = s21_strlen(toStrBuff) + isPositive;
  int spaceLength =
      spaceLengthInit(*flags, intLen, ((isNegative || isPositive) ? 1 : 0));
  formatToStr(*flags, str, toStrBuff, isPositive, spaceLength, 0);
}

void charParse(flag *flags, va_list *arg, char **str) {
  int spaceLength = spaceLengthInit(*flags, 1, 0);
  wchar_t c = 0;
  if (flags->spec == '%') {
    c = '%';
  } else {
    if (flags->length == 'l') {
      c = va_arg(*arg, wchar_t);
    } else {
      c = (char)va_arg(*arg, int);
    }
  }
  char toStrBuff[2] = {0};
  toStrBuff[0] = (char)c;
  formatToStr(*flags, str, toStrBuff, 0, spaceLength, 0);
}

void unsignedParse(flag *flags, va_list *arg, char **str) {
  uint64_t u = va_arg(*arg, uint64_t);
  if (flags->length == 'l' || flags->spec == 'p') {
    u = (uint64_t)u;
  } else if (flags->length == 'h') {
    u = (uint16_t)u;
  } else {
    u = (uint32_t)u;
  }
  int offset = 0;
  int isUpperCase = (flags->spec == 'X' ? 1 : 0);
  char toStrBuff[10000] = {'\0'};
  if (flags->spec == 'p' ||
      ((((flags->spec == 'x' || flags->spec == 'o' || flags->spec == 'X') &&
         flags->hashFlag)) &&
       u != 0)) {
    toStrBuff[0] = '0';
    offset = 1;
    if (flags->spec == 'p' || flags->spec == 'x') {
      toStrBuff[1] = 'x';
      offset = 2;
    }
    if (flags->spec == 'X') {
      toStrBuff[1] = 'X';
      offset = 2;
    }
  }
  int base = 10;
  if (flags->spec == 'x' || flags->spec == 'X' || flags->spec == 'p') {
    base = 16;
  } else if (flags->spec == 'o') {
    base = 8;
  }
  if (!((flags->spec == 'u' || flags->spec == 'p' || flags->spec == 'o' ||
         flags->spec == 'x' || flags->spec == 'X') &&
        u == 0 && flags->accuracy == 0)) {
    unsignedToString(u, &toStrBuff[offset], base, isUpperCase);
  }
  int intLen = s21_strlen(toStrBuff);
  int spaceLength = spaceLengthInit(*flags, intLen, 0);
  int nullLength = nullLengthInit(*flags, intLen, offset);
  if (flags->accuracy == intLen && flags->spec != 'x' && flags->spec != 'X') {
    nullLength = 0;
  }
  formatToStr(*flags, str, toStrBuff, 0, spaceLength, nullLength);
}

int nullLengthInit(flag flags, int intLen, int offset) {
  int nullLength = 0;
  if (flags.spec == 'o') {
    nullLength = flags.accuracy - intLen;
  } else {
    nullLength = (flags.accuracy - intLen) + offset;
  }
  return nullLength;
}

void mantissParse(flag *flags, va_list *arg, char **str) {
  flags->accuracy == -1 ? flags->accuracy = 6 : flags->accuracy;
  long double e =
      flags->length == 'L' ? va_arg(*arg, long double) : va_arg(*arg, double);
  int isUpperCase = (flags->spec == 'E') ? 1 : 0;
  int isPositive = (flags->plus && (e >= 0)) ? 1 : 0;
  int isNegative = (e < 0) ? 1 : 0;
  char toStrBuff[100000] = {'\0'};
  mantissToString(e, flags, toStrBuff, isUpperCase);
  int intLen = s21_strlen(toStrBuff);
  int spaceLength = spaceLengthInit(*flags, intLen, isNegative);
  formatToStr(*flags, str, toStrBuff, isPositive, spaceLength, 0);
}

void shortestViewNumParse(flag *flags, va_list *arg, char **str) {
  long double g =
      flags->length == 'L' ? va_arg(*arg, long double) : va_arg(*arg, double);
  int isPositive = (flags->plus && (g >= 0)) ? 1 : 0;
  int isNegative = (g < 0) ? 1 : 0;
  int isUpperCase = flags->spec == 'G' ? 1 : 0;
  int leftSideIntLength = intLenInit((int)g);
  char toStrBuff[512] = {'\0'};
  int pow = 0;
  long double tmp_g = g;

  if ((int)g - g) {
    while ((int)tmp_g == 0) {
      pow++;
      tmp_g *= 10;
    }
  }
  if (((leftSideIntLength > flags->accuracy) && (flags->accuracy != -1) &&
       (leftSideIntLength > 1)) ||
      pow > 4) {
    if (flags->accuracy == -1) {
      flags->accuracy = 6 - leftSideIntLength;
    } else {
      flags->accuracy ? flags->accuracy -= 1 : flags->accuracy;
    }
    mantissToString(g, flags, toStrBuff, isUpperCase);
  } else {
    flags->accuracy == -1 ? flags->accuracy = 6 : flags->accuracy;
    flags->accuracy -= leftSideIntLength;
    if (pow && flags->accuracy <= 0) {
      flags->accuracy = pow;
    }
    if (g == (int)g) {
      intToString((int)g, toStrBuff);
    } else {
      doubleToString(g, toStrBuff, *flags);
    }
  }
  int intLen = s21_strlen(toStrBuff) + isPositive;
  int spaceLength =
      spaceLengthInit(*flags, intLen, (isNegative || isPositive) ? 1 : 0);
  formatToStr(*flags, str, toStrBuff, isPositive, spaceLength, 0);
}

void stringParse(flag *flags, va_list *arg, char **str) {
  char *tmp = (char *)va_arg(*arg, char *);
  char toStrBuff[100000] = {'\0'};
  if (tmp == s21_NULL) {
    s21_strcpy(toStrBuff, "(null)");
  } else {
    s21_strcpy(toStrBuff, tmp);
  }
  int strLength = s21_strlen(toStrBuff);
  if ((flags->accuracy < strLength) && (flags->accuracy != -1)) {
    toStrBuff[flags->accuracy] = '\0';
    strLength = flags->accuracy;
  } else if (flags->accuracy == 0) {
    toStrBuff[0] = '\0';
  }
  int spaceLength = spaceLengthInit(*flags, strLength, 0);
  formatToStr(*flags, str, toStrBuff, 0, spaceLength, 0);
}

int spaceLengthInit(flag flags, int intLen, int isSignNeed) {
  int spaceLength = 0;
  if (flags.spec == 'u' || flags.spec == 'p' || flags.spec == 'o' ||
      flags.spec == 'x' || flags.spec == 'X' || flags.spec == 'd' ||
      flags.spec == 'i') {
    spaceLength = flags.width - (((flags.accuracy && (flags.accuracy > intLen))
                                      ? flags.accuracy
                                      : intLen));
  } else {
    spaceLength = flags.width - intLen;
  }
  if (flags.space && !isSignNeed &&
      (flags.spec == 'd' || flags.spec == 'i' || flags.spec == 'e' ||
       flags.spec == 'E' || flags.spec == 'g' || flags.spec == 'G' ||
       flags.spec == 'f')) {
    spaceLength -= 1;
  }
  return spaceLength;
}

void mantissToString(long double val, flag *flags, char *toStrBuff,
                     int isUpperCase) {
  int numPow = 0;
  long double rounding = round(pow(10., flags->accuracy));
  long double leftSideNum = 0;
  long double rightSideNum = modfl(val, &leftSideNum);
  if ((rightSideNum > 0.5) && flags->accuracy == 0) {
    val += 1.;
  }
  if (flags->accuracy > 0) {
    (rightSideNum < 0) ? rightSideNum *= -1 : rightSideNum;
    for (int i = 0; i < flags->accuracy; i++) {
      rightSideNum *= 10.;
    }
    if (roundl(rightSideNum) >= rounding) {
      val += 1.;
    }
  }

  char sign = ((int)val == 0) ? '-' : '+';
  if ((int)val - val) {
    for (; (int)val == 0; numPow++, val *= 10)
      ;
  } else {
    sign = '+';
  }
  for (; ((int)val / 10) != 0; numPow++, val /= 10)
    ;
  doubleToString(val, toStrBuff, *flags);
  int bufLen = s21_strlen(toStrBuff);
  toStrBuff[bufLen] = isUpperCase ? 'E' : 'e';
  toStrBuff[bufLen + 1] = sign;
  toStrBuff[bufLen + 3] = numPow % 10 + '0';
  numPow /= 10;
  toStrBuff[bufLen + 2] = numPow % 10 + '0';
}

void formatToStr(flag flags, char **str, char *toStrBuff, int isPositive,
                 int spaceLength, int nullLength) {
  int flag = 0;
  if ((flags.nullFlag && isPositive) || (flags.nullFlag && *toStrBuff == '-' &&
                                         (spaceLength > 0 || nullLength > 0))) {
    if (isPositive) {
      **str = '+';
    } else {
      **str = *toStrBuff;
      toStrBuff++;
    }
    *str = *str + 1;
    flag = 1;
  }
  if (*toStrBuff != '-' && flags.space && !flag && !isPositive &&
      (flags.spec == 'd' || flags.spec == 'i' || flags.spec == 'e' ||
       flags.spec == 'E' || flags.spec == 'f' || flags.spec == 'g' ||
       flags.spec == 'G')) {
    **str = ' ';
    *str = *str + 1;
  }
  if (flags.width && !flags.minus) {
    char sym = flags.nullFlag ? '0' : ' ';
    for (int i = 0; i < spaceLength; i++, *str = *str + 1) {
      **str = sym;
    }
  }
  if (flags.plus && isPositive && flags.spec != 'c' && flags.spec != 'u' &&
      !flags.nullFlag) {
    **str = '+';
    *str = *str + 1;
  }
  if (flags.spec == 'd' || flags.spec == 'u' || flags.spec == 'x' ||
      flags.spec == 'X' || flags.spec == 'i' || flags.spec == 'o' ||
      flags.spec == 'p') {
    if (*toStrBuff == '-' && !flags.nullFlag) {
      **str = *toStrBuff;
      toStrBuff++;
      *str += 1;
    } else if (*(toStrBuff + 1) == 'x' || *(toStrBuff + 1) == 'X') {
      for (int i = 0; i < 2; i++, toStrBuff++, *str += 1) {
        **str = *toStrBuff;
      }
    }
    for (int i = 0; i < nullLength; *str = *str + 1, i++) {
      **str = '0';
    }
  }
  if (flags.spec != 'c') {
    s21_strcpy(*str, toStrBuff);
    *str = *str + s21_strlen(toStrBuff);
  } else {
    **str = toStrBuff[0];
    *str = *str + 1;
  }
  if (flags.width && flags.minus) {
    for (int i = 0; i < spaceLength; i++, *str = *str + 1) {
      **str = ' ';
    }
  }
}

int intLenInit(long int n) {
  int len = 0;
  if (n == 0) {
    len = 1;
  } else {
    if (n < 0) {
      n = n * (-1);
    }

    while (n > 0) {
      len++;
      n /= 10;
    }
  }
  return len;
}

void intToString(long long int n, char s[]) {
  long int i = 0;
  long int sign = 0;
  if ((sign = n) < 0) {
    n = -n;
  }

  i = 0l;
  do {
    s[i++] = n % 10 + '0';
  } while ((n /= 10) > 0);
  if (sign < 0) {
    s[i++] = '-';
  }
  s[i] = '\0';
  strReverse(s);
}

void strReverse(char s[]) {
  int i = 0, j = 0;

  for (i = 0, j = s21_strlen(s) - 1; i < j; i++, j--) {
    char c = 0;
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

void unsignedToString(uint64_t u, char *str, int base, int isUpperCase) {
  uint64_t t = 0;
  uint64_t tmp = u;
  int count = 0;
  char c = isUpperCase ? 'A' : 'a';
  if (tmp == 0) {
    count++;
  }
  while (tmp > 0) {
    tmp = tmp / base;
    count++;
  }
  str += count;
  *str = '\0';
  do {
    uint64_t res = 0;
    res = u - base * (t = u / base);
    if (res < 10) {
      *--str = '0' + res;
    } else if (res < 16) {
      *--str = c - 10 + res;
    }
  } while ((u = t) != 0);
}

void doubleToString(long double val, char *buf, flag flags) {
  int offset = 0;
  if (val < 0) {
    buf[offset] = '-';
    offset = 1;
    val = val * -1.;
  }
  long double rounding = round(pow(10., flags.accuracy));
  long double leftSideNum = 0;
  long double rightSideNum = modfl(val, &leftSideNum);
  if ((rightSideNum > 0.5) && flags.accuracy == 0) {
    leftSideNum += 1.;
  }
  if (flags.accuracy > 0) {
    (rightSideNum < 0) ? rightSideNum *= -1 : rightSideNum;
    for (int i = 0; i < flags.accuracy; i++) {
      rightSideNum *= 10.;
    }
    if (roundl(rightSideNum) >= rounding) {
      leftSideNum += 1.;
    }
  }
  rightSideNum = (roundl(rightSideNum) / rounding -
                  (long long)(roundl(rightSideNum) / rounding));
  intToString((long long int)leftSideNum, &buf[offset]);
  if (flags.accuracy > 0) {
    int bufLen = s21_strlen(buf);
    buf[bufLen] = '.';
    bufLen++;
    for (int i = 0; i < flags.accuracy; i++) {
      rightSideNum *= 10.0;
      if ((long int)rightSideNum == 0) {
        buf[bufLen] = '0';
        bufLen++;
      }
    }
    if (round(rightSideNum)) {
      intToString(round(rightSideNum), &buf[bufLen]);
    }
  } else if (flags.hashFlag) {
    buf[s21_strlen(buf)] = '.';
  }
  if ((flags.spec == 'g' || flags.spec == 'G') && !flags.hashFlag &&
      flags.accuracy) {
    int i = s21_strlen(buf) - 1;
    for (; buf[i] == '0'; i--) {
      buf[i] = '\0';
    }
    if (buf[i] == '.') {
      buf[i] = '\0';
    }
  }
}

int s21_atoi(const char *str) {
  int res = 0;
  for (int i = 0; str[i] != '\0'; ++i) res = res * 10 + str[i] - '0';
  if (str[0] == '-') res *= -1;
  return res;
}

void w_stringParse(flag *flags, va_list *arg, char **str) {
  wchar_t *w_tmp = (wchar_t *)va_arg(*arg, wchar_t *);
  char tmp[10000] = {0};
  if (w_tmp != s21_NULL) to_char(w_tmp, tmp, 10000);
  char toStrBuff[100000] = {'\0'};
  if (w_tmp == s21_NULL) {
    s21_strcpy(toStrBuff, "(null)");
  } else {
    s21_strcpy(toStrBuff, tmp);
  }
  int strLength = s21_strlen(toStrBuff);
  if ((flags->accuracy < strLength) && (flags->accuracy != -1)) {
    toStrBuff[flags->accuracy] = '\0';
    strLength = flags->accuracy;
  } else if (flags->accuracy == 0) {
    toStrBuff[0] = '\0';
  }
  int spaceLength = spaceLengthInit(*flags, strLength, 0);
  formatToStr(*flags, str, toStrBuff, 0, spaceLength, 0);
}

s21_size_t to_char(const wchar_t *src, char *dest, s21_size_t dest_len) {
  s21_size_t i = 0;
  while (i < (dest_len - 1) && src[i] != '\0') {
    wchar_t code = src[i];
    if (code < 128)
      dest[i] = (char)code;
    else {
      dest[i] = '?';
      if (code >= 0xD800 && code <= 0xD8FF) i++;
    }
    i++;
  }
  dest[i] = '\0';
  return i - 1;
}
