#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *upstr = s21_NULL;

  if (str) {
    upstr = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
    for (int i = 0; str[i] != '\0'; i++) {
      if ((int)str[i] > 96 && (int)str[i] < 123)
        upstr[i] = (int)str[i] - 32;
      else
        upstr[i] = str[i];
    }
  }

  return upstr;
}

void *s21_to_lower(const char *str) {
  char *lowstr = s21_NULL;
  if (str) {
    lowstr = (char *)calloc(s21_strlen(str) + 1, sizeof(char));
    for (int i = 0; str[i] != '\0'; i++) {
      if ((int)str[i] > 64 && (int)str[i] < 91)
        lowstr[i] = (int)str[i] + 32;
      else
        lowstr[i] = str[i];
    }
  }

  return lowstr;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  char *insstr = s21_NULL;
  s21_size_t p = 0;
  s21_size_t srcLen = 0;
  s21_size_t strLen = 0;
  srcLen = ((src == s21_NULL) ? 0 : s21_strlen(src));
  strLen = ((str == s21_NULL) ? 0 : s21_strlen(str));

  if (src && (start_index <= srcLen)) {
    insstr = (char *)calloc(srcLen + strLen + 1, sizeof(char));
    if (insstr) {
      for (int i = 0; src[i] != '\0'; i++) {
        if (p == start_index && str != s21_NULL) {
          for (int j = 0; str[j] != '\0'; j++) {
            insstr[p] = str[j];
            p++;
          }
        }
        insstr[p] = src[i];
        p++;
      }
    }
  }

  return insstr;
}

int numfirst(const char *src, const char *trim_chars, int first, int trim) {
  int iter = 0;
  for (int i = 0; i < trim; i++) {
    if (src[first] == trim_chars[i]) iter = 1;
  }

  return iter;
}

int numlast(const char *src, const char *trim_chars, int last, int trim) {
  int iter = 0;
  last--;
  for (int i = 0; i < trim; i++) {
    if (src[last] == trim_chars[i]) iter = 1;
  }

  return iter;
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *trimsrc = s21_NULL;

  if (src) {
    if (trim_chars && *trim_chars) {
      int first = 0, last = s21_strlen(src), trim = s21_strlen(trim_chars);
      trimsrc = (char *)calloc(s21_strlen(src) + 1, sizeof(char));

      while (numfirst(src, trim_chars, first, trim)) {
        first++;
      }

      if (first != last) {
        while (numlast(src, trim_chars, last, trim)) {
          last--;
        }
      }

      for (int i = 0; first < last; i++) {
        trimsrc[i] = src[first];
        first++;
      }
    } else {
      trimsrc = s21_trim(src, "\t\n ");
    }
  }
  return trimsrc;
}
