#include "s21_test.h"

//   STRLEN TESTS
START_TEST(strlen_test1) {
  char str[] = "sdgfsdfgsgssadfgKLDHJHGJHGJLHGHLKDHh";

  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST;

START_TEST(strlen_test2) {
  char str[] = "";

  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST;

START_TEST(strlen_test3) {
  char str[] = "s21_NULL";

  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST;

START_TEST(strlen_test4) {
  char str[] = "\0";

  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST;

START_TEST(strlen_test5) {
  char str[] = {'3', '4', 'r', 'e'};

  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST;
//   STRLEN TESTS
//
//
//
//   STRCMP TESTS
START_TEST(strcmp_test1) {
  char str1[] = "privet rrfrfrfr";
  char str2[] = "privet rrfrfrfr";

  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST;

START_TEST(strcmp_test2) {
  char str1[] = "";
  char str2[] = "";

  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST;

START_TEST(strcmp_test3) {
  char str1[] = "1              7";
  char str2[] = "1              7";

  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST;

START_TEST(strcmp_test4) {
  char str1[] = "\0";
  char str2[] = "\0";

  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST;

START_TEST(strcmp_test5) {
  char str1[] = {'0', '1', '2'};
  char str2[] = {'0', '1', '2'};

  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
}
END_TEST;
//   STRCMP TESTS
//
//
//
//   MEMCHR TESTS
START_TEST(memchr_test1) {
  char str[] = "Hello world";
  char c = ' ';
  s21_size_t n = 11;

  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST;

START_TEST(memchr_test2) {
  char str[] = " ";
  char c = ' ';
  s21_size_t n = 1;

  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST;

START_TEST(memchr_test3) {
  char str[] = "aboba ";
  char c = 'b';
  s21_size_t n = 11;

  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST;

START_TEST(memchr_test4) {
  char str[] = "            d";
  char c = 'd';
  s21_size_t n = 2;

  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST;

START_TEST(memchr_test5) {
  char str[] = "\0";
  char c = '\0';
  s21_size_t n = 11;

  ck_assert_ptr_eq(s21_memchr(str, c, n), memchr(str, c, n));
}
END_TEST;
//   MEMCHR TESTS
//
//
//
//   MEMCPY TESTS
START_TEST(memcpy_test1) {
  const char str1[] = "wrwejroewrwerwerwerwe";
  s21_size_t n = 5;
  char str2[6] = {0};
  char str3[6] = {0};

  void *ptr1 = s21_memcpy(str2, str1, n);
  void *ptr2 = memcpy(str3, str1, n);

  ck_assert_str_eq(str2, str3);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST;

START_TEST(memcpy_test2) {
  const char str1[] = "Hello";
  s21_size_t n = 5;
  char str2[6] = {0};
  char str3[6] = {0};

  void *ptr1 = s21_memcpy(str2, str1, n);
  void *ptr2 = memcpy(str3, str1, n);

  ck_assert_str_eq(str2, str3);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST;

START_TEST(memcpy_test3) {
  const char str1[] = " ";
  s21_size_t n = 1;
  char str2[6] = {0};
  char str3[6] = {0};

  void *ptr1 = s21_memcpy(str2, str1, n);
  void *ptr2 = memcpy(str3, str1, n);

  ck_assert_str_eq(str2, str3);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST;

START_TEST(memcpy_test4) {
  const char str1[] = "OF MIGHT MAGIC";
  s21_size_t n = 100;
  char str2[100] = "HEROES";
  char str3[100] = "HEROES";

  void *ptr1 = s21_memcpy(str2, str1, n);
  void *ptr2 = memcpy(str3, str1, n);

  ck_assert_str_eq(str2, str3);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST;
//   MEMCPY TESTS
//
//
//
//   MEMMOVE TESTS
START_TEST(memmove_test) {
  const char str1[] = "Hello";
  s21_size_t n = 5;
  char str2[9] = {0};
  char str3[9] = {0};

  void *ptr1 = s21_memmove(str2, str1, n);
  void *ptr2 = memmove(str3, str1, n);

  ck_assert_str_eq(str2, str3);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST;

//   MEMMOVE TESTS
//
//
//
//   MEMSET TESTS
START_TEST(memset_test) {
  char str1[] = "Helsdfsflo";
  char str2[] = "Helsdfsflo";
  char k = '1';
  s21_size_t n = 8;

  void *ptr1 = s21_memset(str2, k, n);
  void *ptr2 = memset(str1, k, n);

  ck_assert_str_eq(str1, str2);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST;

START_TEST(strcat_test) {
  char str1[100] = "Hello";
  char str2[100] = "Poka";
  char str3[100] = "Hello";
  char str4[100] = "Poka";

  char *ptr1 = s21_strcat(str1, str2);
  char *ptr2 = strcat(str3, str4);

  ck_assert_str_eq(str1, str3);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST;

START_TEST(strncat_test) {
  char str1[100] = "Hello";
  char str2[100] = "Poka";
  char str3[100] = "Hello";
  char str4[100] = "Poka";
  s21_size_t n = 3;

  char *ptr1 = s21_strncat(str1, str2, n);
  char *ptr2 = strncat(str3, str4, n);

  ck_assert_str_eq(str1, str3);
  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST;

START_TEST(strchr_test) {
  char str1[] = "Hello";
  char c = 'l';

  char *ptr1 = s21_strchr(str1, c);
  char *ptr2 = strchr(str1, c);

  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST;

START_TEST(strncmp_test) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  s21_size_t n = 3;

  int ptr1 = s21_strncmp(str1, str2, n);
  int ptr2 = strncmp(str1, str2, n);

  ck_assert_int_eq(ptr1, ptr2);
}
END_TEST;

START_TEST(strcpy_test) {
  char str1[8] = "";
  char str2[] = "Hello";
  char str3[8] = "";
  char str4[] = "Hello";

  char *ptr1 = s21_strcpy(str1, str2);
  char *ptr2 = strcpy(str3, str4);

  ck_assert_pstr_eq(ptr1, ptr2);
  ck_assert_str_eq(str1, str3);
}
END_TEST;

START_TEST(strncpy_test) {
  char str1[8] = "";
  char str2[] = "Hello";
  char str3[8] = "";
  char str4[] = "Hello";
  s21_size_t n = 3;

  char *ptr1 = s21_strncpy(str1, str2, n);
  char *ptr2 = strncpy(str3, str4, n);

  ck_assert_pstr_eq(ptr1, ptr2);
  ck_assert_str_eq(str1, str3);
}
END_TEST;

START_TEST(strcspn_test1) {
  char str1[] = "loasdfadsfHloadfadsfadfas";
  char str2[] = "lo";

  int ptr1 = s21_strcspn(str1, str2);
  int ptr2 = strcspn(str1, str2);

  ck_assert_int_eq(ptr1, ptr2);
}
END_TEST;

START_TEST(strcspn_test2) {
  char str1[] = "local";
  char str2[] = "bebra";

  int ptr1 = s21_strcspn(str1, str2);
  int ptr2 = strcspn(str1, str2);

  ck_assert_int_eq(ptr1, ptr2);
}
END_TEST;

START_TEST(strpbrk_test) {
  char str1[] = "Hello";
  char str2[] = "ol";

  char *ptr1 = s21_strpbrk(str1, str2);
  char *ptr2 = strpbrk(str1, str2);

  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST;

START_TEST(strrchr_test) {
  char str1[] = "Hello";
  char sym = 'l';

  char *ptr1 = s21_strrchr(str1, sym);
  char *ptr2 = strrchr(str1, sym);

  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST;

START_TEST(strspn_test) {
  char str1[] = "Hello";
  char str2[] = "lHe";

  s21_size_t ptr1 = s21_strspn(str1, str2);
  s21_size_t ptr2 = strspn(str1, str2);

  ck_assert_int_eq(ptr1, ptr2);
}
END_TEST;

START_TEST(strstr_test) {
  char str1[] = "Hello";
  char str2[] = "lo";

  char *ptr1 = s21_strstr(str1, str2);
  char *ptr2 = strstr(str1, str2);

  ck_assert_pstr_eq(ptr1, ptr2);
}
END_TEST;

// MEMCMP TESTS
START_TEST(memcmp_test1) {
  char str1[] = "Helpo";
  char str2[] = "";
  s21_size_t n = 0;

  int ptr2 = memcmp(str1, str2, n);
  int ptr1 = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(ptr1, ptr2);
}
END_TEST;

START_TEST(memcmp_test2) {
  char str1[] = "Hello";
  char str2[] = "Hello";
  s21_size_t n = 5;

  int ptr2 = memcmp(str1, str2, n);
  int ptr1 = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(ptr1, ptr2);
}
END_TEST;

START_TEST(memcmp_test3) {
  char str1[] = "Hello";
  char str2[] = "pello";
  s21_size_t n = 5;

  int ptr2 = memcmp(str1, str2, n);
  int ptr1 = s21_memcmp(str1, str2, n);

  ck_assert_int_eq(ptr1, ptr2);
}
END_TEST;

// STRERROR TESTS
START_TEST(strerror_test) {
  char *str1 = (char *)calloc(100, sizeof(char));
  char *str2 = (char *)calloc(100, sizeof(char));
  int i = 0;
  while (i < 134) {
    str1 = s21_strerror(i);
    str2 = strerror(i);
    ck_assert_str_eq(str1, str2);
    i++;
  }
}
END_TEST;

// STRTOK TESTS
START_TEST(strtok_test1) {
  char str1[] = "test1/test2/test3";
  char str2[] = "/";
  char *ptr1 = s21_NULL;
  char *ptr2 = s21_NULL;

  ptr1 = strtok(str1, str2);
  ptr2 = s21_strtok(str1, str2);

  ck_assert_pstr_eq(ptr1, ptr2);

  while (ptr1 && ptr2) {
    ck_assert_pstr_eq(ptr1, ptr2);
    ptr1 = strtok(s21_NULL, str2);
    ptr2 = s21_strtok(s21_NULL, str2);
  }
}
END_TEST;

START_TEST(strtok_test2) {
  char str1[] = "test1/test2/test3";
  char str2[] = "test1/test2/test3";
  char *ptr1 = s21_NULL;
  char *ptr2 = s21_NULL;

  ptr1 = strtok(str1, str2);
  ptr2 = s21_strtok(str1, str2);

  ck_assert_pstr_eq(ptr1, ptr2);

  while (ptr1 && ptr2) {
    ck_assert_pstr_eq(ptr1, ptr2);
    ptr1 = strtok(s21_NULL, str2);
    ptr2 = s21_strtok(s21_NULL, str2);
  }
}
END_TEST;

START_TEST(strtok_test3) {
  char str1[] = "aboba";
  char str2[] = "prank";
  char *ptr1 = s21_NULL;
  char *ptr2 = s21_NULL;

  ptr1 = strtok(str1, str2);
  ptr2 = s21_strtok(str1, str2);

  ck_assert_pstr_eq(ptr1, ptr2);

  while (ptr1 && ptr2) {
    ck_assert_pstr_eq(ptr1, ptr2);
    ptr1 = strtok(s21_NULL, str2);
    ptr2 = s21_strtok(s21_NULL, str2);
  }
}
END_TEST;

START_TEST(strtok_test4) {
  char str1[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  char str2[] = "!Stepa__ !M!ish a____Anton+An!!!drey";
  const char delims[] = "+_! =";
  char *got = s21_strtok(str1, delims);
  char *expected = strtok(str2, delims);
  ck_assert_uint_eq(s21_strlen(got), s21_strlen(expected));
  ck_assert_str_eq(got, expected);
  while (got || expected) {
    got = s21_strtok(s21_NULL, delims);
    expected = strtok(s21_NULL, delims);
    if (got || expected) {
      ck_assert_str_eq(got, expected);
    } else {
      ck_assert_ptr_null(got);
      ck_assert_ptr_null(expected);
    }
  }
}
END_TEST

// START_TEST(strtok_test4) {
//     char str1[] = "++++++++";
//     char str2[] = "++++++++";
//     const char delims[] = "+_! =";
//     char* got = s21_strtok(str1, delims);
//     char* expected = strtok(str2, delims);
//     ck_assert_ptr_null(got);
//     ck_assert_ptr_null(expected);
// }
// END_TEST

Suite *string_test(void) {
  Suite *s = suite_create("\033[45ms21_string_all\033[0m");
  TCase *tc = tcase_create("s21_string_all");
  // STRLEN TESTS
  tcase_add_test(tc, strlen_test1);
  tcase_add_test(tc, strlen_test2);
  tcase_add_test(tc, strlen_test3);
  tcase_add_test(tc, strlen_test4);
  tcase_add_test(tc, strlen_test5);
  // STRCMP TESTS
  tcase_add_test(tc, strcmp_test1);
  tcase_add_test(tc, strcmp_test2);
  tcase_add_test(tc, strcmp_test3);
  tcase_add_test(tc, strcmp_test4);
  tcase_add_test(tc, strcmp_test5);
  // MEMCHR TESTS
  tcase_add_test(tc, memchr_test1);
  tcase_add_test(tc, memchr_test2);
  tcase_add_test(tc, memchr_test3);
  tcase_add_test(tc, memchr_test4);
  tcase_add_test(tc, memchr_test5);
  // MEMCPY TESTS
  tcase_add_test(tc, memcpy_test1);
  tcase_add_test(tc, memcpy_test2);
  tcase_add_test(tc, memcpy_test3);
  tcase_add_test(tc, memcpy_test4);
  // MEMMOVE TESTS
  tcase_add_test(tc, memmove_test);
  // MEMSET TESTS
  tcase_add_test(tc, memset_test);
  // STRCAT TESTS
  tcase_add_test(tc, strcat_test);
  // STRNCAT TESTS
  tcase_add_test(tc, strncat_test);
  // STRCHR TESTS
  tcase_add_test(tc, strchr_test);
  tcase_add_test(tc, strncmp_test);
  tcase_add_test(tc, strcpy_test);
  tcase_add_test(tc, strncpy_test);
  // STRCSPN TESTS
  tcase_add_test(tc, strcspn_test1);
  tcase_add_test(tc, strcspn_test2);
  tcase_add_test(tc, strpbrk_test);
  tcase_add_test(tc, strrchr_test);
  tcase_add_test(tc, strspn_test);
  tcase_add_test(tc, strstr_test);
  // MEMCMP TESTS
  tcase_add_test(tc, memcmp_test1);
  tcase_add_test(tc, memcmp_test2);
  tcase_add_test(tc, memcmp_test3);
  tcase_add_test(tc, strerror_test);
  // STRTOK TESTS
  tcase_add_test(tc, strtok_test1);
  tcase_add_test(tc, strtok_test2);
  tcase_add_test(tc, strtok_test3);
  tcase_add_test(tc, strtok_test4);
  suite_add_tcase(s, tc);
  return s;
}
