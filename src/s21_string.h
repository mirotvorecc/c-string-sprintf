#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_NULL (void *)0
typedef unsigned long s21_size_t;

#include "s21_sharp.h"
#include "s21_sprintf.h"
// s21_string.h

s21_size_t s21_strlen(const char *str);
int s21_strcmp(char *str1, char *str2);
void *s21_memchr(void *arr, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *newStr, const void *src, s21_size_t n);
void *s21_memmove(void *destination, const void *source, s21_size_t n);
void *s21_memset(void *str, int n, s21_size_t c);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);
char *s21_strerror(int errnum);

#endif  // SRC_S21_STRING_H_
