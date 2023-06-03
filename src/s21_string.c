#include "s21_string.h"

#include "s21_strerror.h"

// считает количество символов в строке
s21_size_t s21_strlen(const char *str) {
  s21_size_t length = 0;
  for (; str[length] != '\0'; length++)
    ;
  return length;
}

// сравнивает две строки: s1 и s2. Она возвращает целое число, которое меньше,
// больше нуля или равно ему, если s1 соответственно меньше, больше или равно
// s2.

int s21_strcmp(char *str1, char *str2) {
  for (; *str1 && *str1 == *str2; str1++, str2++)
    ;
  return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}

// ищет символ в массиве, возвращая его, если найдет, или NULL если не найдет
void *s21_memchr(void *arr, int c, s21_size_t n) {
  void *res = s21_NULL;
  unsigned char *buf = (unsigned char *)arr;
  for (s21_size_t i = 0; i < n && buf; i++) {
    if (*buf == (unsigned char)c && buf) {
      res = buf;
      break;
    }
    buf++;
  }
  return res;
}

// копирует n байт из одного массива в другой
// eсли массивы перекрываются, результат копирования будет не определен.
void *s21_memcpy(void *newStr, const void *src, s21_size_t n) {
  char *bufS = (char *)src;
  char *bufNs = (char *)newStr;
  s21_size_t i = 0;
  for (; i < n; i++) {
    bufNs[i] = bufS[i];
  }
  return bufNs;
}

// копирует n байт из одного массива в другой
// массивы могут перекрываться
void *s21_memmove(void *newStr, const void *src, s21_size_t n) {
  char *buff = (char *)malloc(sizeof(char) * n);

  if (buff) {
    s21_memcpy(buff, (char *)src, n);
    s21_memcpy(newStr, buff, n);
  }

  return newStr;
}

// заполняет первые n байт области памяти, на которую указывает аргумент str
// символом, код которого указывается аргументом c.
void *s21_memset(void *str, int n, s21_size_t c) {
  char *buf = (char *)str;
  for (s21_size_t i = 0; i < c; i++) {
    buf[i] = n;
  }
  return str;
}

// Функция strcat добавляет в строку, на которую указывает аргумент dest
// строку, на которую указывает аргумент str.
// Символ конца строки помещается в конце объединенных строк.
char *s21_strcat(char *dest, const char *str) {
  int destLen = s21_strlen(dest);
  int srcLen = s21_strlen(str);
  int i = destLen, k = 0;
  for (; i < (destLen + srcLen); i++, k++) {
    dest[i] = str[k];
  }
  dest[i] = '\0';  //  ??
  return dest;
}

// Функция strncat добавляет в строку, на которую указывает аргумент destination
// строку, на которую указывает аргумент append
// пока не встретится символ конца строки или пока не будет добавлено n
// символов.
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t destLen = s21_strlen(dest);
  s21_size_t srcLen = s21_strlen(src);
  s21_size_t len = (n > srcLen) ? srcLen : n;
  s21_size_t i = destLen, k = 0;
  for (; i < (len + destLen); i++, k++) {
    dest[i] = src[k];
  }
  dest[i] = '\0';  //  ??
  return dest;
}

// Функция strchr ищет первое вхождения символа
// код которого указан в аргументе c, в строке на которую указывает аргумент
// str.
char *s21_strchr(const char *str, int c) {
  const char *res = s21_NULL;

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == c) {
      res = &str[i];
      break;
    }
  }

  return (char *)res;
}

// побайтно сравнивает две строки, на которые указывают аргументы функции.
// сравнение прекращается если встретились отличающиеся символы
// при этом возвращается отрицательное или положительное число
// если были проверены n символов или обе сравниваемые строки закончились
// и отличий не было, то сравнение прекращается и возвращается ноль.
int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  int res = 0;
  if (*str2 && *str1) {
    for (; (*str1 == *str2) && n; str1++, str2++, n--)
      ;

    res = *(const unsigned char *)str1 - *(const unsigned char *)str2;
  }
  return res;
}

// копирует данные из строки, на которую указывает аргумент src в строку
// на которую указывает аргумент dest, пока не встретится символ конца строки
// копирование производится вместе с символом конца строки.
// eсли строки перекрываются, результат копирования будет не определен.
char *s21_strcpy(char *dest, const char *src) {
  int i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}

// копирует данные из строки, на которую указывает аргумент src
// в строку на который указывает аргумент dest, пока не встретится символ конца
// строки или количество скопированных символов не достигнет величины указанной
// в аргументе n. при этом символ конца строки не копируется.

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  int i = 0;
  s21_memset(dest, '\0', n);
  while ((src[i] != '\0') && (n > 0)) {
    dest[i] = src[i];
    i++;
    n--;
  }
  return dest;
}

// Функция strcspn определяет наибольшую длину начального участка строки, на
// которую указывает аргумент str1, не содержащего не один из символов строки,
// на которую указывает аргумент str2
s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  const char *i = str1;
  int equal = 0;

  while (*i) {
    const char *k = str2;
    while (*k) {
      if (*i == *k) {
        equal = 1;
        break;
      } else {
        k++;
      }
    }
    if (equal) {
      break;
    }
    i++;
    res++;
  }
  return res;
}

// ищет первое вхождение в строку, на которую указывает аргумент str1
// одного из символов, входящих в строку, на которую указывает аргумент str2.
char *s21_strpbrk(const char *str1, const char *str2) {
  const char *res = s21_NULL;
  int k = 0;

  for (int i = 0; str1[i] != '\0'; i++) {
    for (k = 0; str2[k] != '\0'; k++) {
      if (str1[i] == str2[k]) {
        res = &str1[i];
        break;
      }
    }
    if (str1[i] == str2[k]) {
      break;
    }
  }

  return (char *)res;
}

char *s21_strrchr(const char *str, int c) {
  char *res = s21_NULL;

  for (int i = s21_strlen(str); i >= 0; i--) {
    if (str[i] == c) {
      res = (char *)&str[i];
      break;
    }
  }

  return res;
}
// определяет наибольшую длину начального участка строки на которую указывает
// аргумент str содержащего только символы строки на которую указывает аргумент
// str2. если первый символ строки str не входит в строку str2, то возвращаемая
// длина – 0.
s21_size_t s21_strspn(const char *str1, const char *str2) {
  s21_size_t res = 0;
  int k = 0;

  for (int i = 0; str1[i] != '\0'; i++) {
    for (k = 0; k < str2[k]; k++) {
      if (str1[i] == str2[k]) {
        break;
      }
    }
    if (str1[i] == str2[k]) {
      res++;
    } else {
      break;
    }
  }

  return res;
}

// ищет первое вхождение строки (за исключением признак конца строки)
// на которую указывает аргумент str2, в строку , на которую указывает аргумент
// str1 если строка str2 имеет нулевую длину, то функция вернет указатель на
// начало строки str1
char *s21_strstr(const char *str1, const char *str2) {
  const char *res = s21_NULL;
  s21_size_t i = 0;
  int k = 0;
  int j = 0;

  if (s21_strlen(str1) >= s21_strlen(str2)) {
    while (i <= (s21_strlen(str1) - s21_strlen(str2))) {
      int equal = 1;
      while (str2[k]) {
        if (str1[i + j] != str2[k]) {
          equal = 0;
          break;
        }
        j++;
        k++;
      }
      i++;
      if (equal) {
        res = str1 + i - 1;
        break;
      }
    }
  }
  return (char *)res;
}
// побайтно сравнивает два массива (области памяти), на которые указывают
// аргументы str1 и str2 каждый байт массива определяется типом unsigned char.
// Сравнение продолжается, пока не будут проверено n байт или пока не встретятся
// отличающиеся байты
int s21_memcmp(const void *str1, const void *str2, size_t n) {
  int result = 0;
  for (; *(char *)str1 && *(char *)str2 && *(char *)str1 == *(char *)str2;
       str1++, str2++, n--)
    ;
  if (n) result = *(unsigned char *)str1 - *(unsigned char *)str2;
  return result;
}

// возвращает строку, описывающую код ошибки, переданный в аргументе error_code
char *s21_strerror(int error_code) {
  static char dest[512] = {'\0'};
  if (error_code >= 0 && error_code <= ERROR_LIST_SIZE) {
    s21_strcpy(dest, errors[error_code]);
  } else {
    s21_sprintf(dest, "Unknown error: %d", error_code);
  }
  return dest;
}

// выделяет очередную часть строки, на которую указывает аргумент str
// отделенную одним из символов разделителей указанных в строке, на которую
// указывает аргумент delim последовательный вызов функции strtok приводит к
// разбиению строки str на части (лексемы).
char *s21_strtok(char *str, const char *delim) {
  static char *buf;
  char *ch = s21_NULL;

  if (str) {
    buf = str;
    while (*buf && s21_strchr(delim, *buf)) {
      *buf++ = '\0';
    }
  }
  if (buf && *buf) {
    str = buf;
    while (*buf && !s21_strchr(delim, *buf)) {
      ++buf;
    }
    while (*buf && s21_strchr(delim, *buf)) {
      *buf++ = '\0';
    }
    ch = str;
  }
  return ch;
}
