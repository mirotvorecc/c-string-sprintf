#ifndef SRC_S21_SPRINTF_H_
#define SRC_S21_SPRINTF_H_

#include "s21_string.h"
typedef struct {
  int plus;
  int minus;
  int space;
  int width;
  int nullFlag;
  int hashFlag;
  char spec;
  int accuracy;
  char length;
} flag;

int s21_sprintf(char *str, const char *format, ...);
void specs_parser(flag *flags, va_list *arg, char **str, const char *format);
void flags_parser(const char **format, flag *flags, va_list *arg);
int intLenInit(long int n);
void intToString(long long int n, char s[]);
void strReverse(char s[]);
void doubleToString(long double val, char *buf, flag flags);
void intParse(flag *flags, va_list *arg, char **str);
void doubleParse(flag *flags, va_list *arg, char **str);
void charParse(flag *flags, va_list *arg, char **str);
void unsignedParse(flag *flags, va_list *arg, char **str);
void mantissParse(flag *flags, va_list *arg, char **str);
void stringParse(flag *flags, va_list *arg, char **str);
void shortestViewNumParse(flag *flags, va_list *arg, char **str);
void formatToStr(flag flags, char **str, char *toStrBuff, int isPositive,
                 int spaceLength, int nullLength);
void unsignedToString(uint64_t u, char *str, int base, int isUpperCase);
void mantissToString(long double val, flag *flags, char *toStrBuff,
                     int isUpperCase);
int spaceLengthInit(flag flags, int intLen, int isSignNeed);
int nullLengthInit(flag flags, int intLen, int offset);
int s21_atoi(const char *str);
void w_stringParse(flag *flags, va_list *arg, char **str);
s21_size_t to_char(const wchar_t *src, char *dest, s21_size_t dest_len);

#endif  // SRC_S21_SPRINTF_H_
