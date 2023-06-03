#include "s21_test.h"

START_TEST(s21_to_lower_strnull) {
  char str1[] = "";
  char *str2 = s21_to_lower(str1);
  char *expected = "";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_to_lower_1) {
  char str1[] = "ABCXYZ";
  char *str2 = s21_to_lower(str1);
  char *expected = "abcxyz";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_to_lower_2) {
  char str1[] = "PRIvet RebIata";
  char *str2 = s21_to_lower(str1);
  char *expected = "privet rebiata";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_to_lower_3) {
  char str1[] = "tut tolko malishy";
  char *str2 = s21_to_lower(str1);
  char *expected = "tut tolko malishy";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_to_lower_4) {
  char str1[] = "123malish";
  char *str2 = s21_to_lower(str1);
  char *expected = "123malish";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_to_lower_5) {
  char str1[] = "123MALISH";
  char *str2 = s21_to_lower(str1);
  char *expected = "123malish";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_to_lower_6) {
  char str1[] = "@(-_-){";
  char *str2 = s21_to_lower(str1);
  char *expected = "@(-_-){";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_to_upper_strnull) {
  char str1[] = "";
  char *str2 = s21_to_upper(str1);
  char *expected = "";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_to_upper_1) {
  char str1[] = "abcxyz";
  char *str2 = s21_to_upper(str1);
  char *expected = "ABCXYZ";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_to_upper_2) {
  char str1[] = "TuT EShe est bolshyi";
  char *str2 = s21_to_upper(str1);
  char *expected = "TUT ESHE EST BOLSHYI";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_to_upper_3) {
  char str1[] = "TUT TOLKO BOLSHYI";
  char *str2 = s21_to_upper(str1);
  char *expected = "TUT TOLKO BOLSHYI";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_to_upper_4) {
  char str1[] = "123malish";
  char *str2 = s21_to_upper(str1);
  char *expected = "123MALISH";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_to_upper_5) {
  char str1[] = "123MALISH";
  char *str2 = s21_to_upper(str1);
  char *expected = "123MALISH";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_to_upper_6) {
  char str1[] = "@(-_-){";
  char *str2 = s21_to_upper(str1);
  char *expected = "@(-_-){";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_insert_1) {
  char str1[] = "mne prosto ";
  char str2[] = " poh";
  int index = 10;
  char *str3 = s21_insert(str1, str2, index);
  char *expected = "mne prosto poh ";

  ck_assert_str_eq(str3, expected);

  free(str3);
}
END_TEST;

START_TEST(s21_insert_2) {
  char str1[] = "mne prosto";
  char str2[] = " poh";
  int index = 3;
  char *str3 = s21_insert(str1, str2, index);
  char *expected = "mne poh prosto";

  ck_assert_str_eq(str3, expected);

  free(str3);
}
END_TEST;

START_TEST(s21_insert_3) {
  char str1[] = "mne prosto yi";
  char str2[] = "poh";
  int index = 11;
  char *str3 = s21_insert(str1, str2, index);
  char *expected = "mne prosto pohyi";

  ck_assert_str_eq(str3, expected);

  free(str3);
}
END_TEST;

START_TEST(s21_insert_4) {
  char str1[] = "mne prosto";
  char str2[] = "poh ";
  int index = 0;
  char *str3 = s21_insert(str1, str2, index);
  char *expected = "poh mne prosto";

  ck_assert_str_eq(str3, expected);

  free(str3);
}
END_TEST;

START_TEST(s21_insert_5) {
  char str1[] = "2 + 2 = ";
  char str2[] = " pyti";
  int index = 7;
  char *str3 = s21_insert(str1, str2, index);
  char *expected = "2 + 2 = pyti ";

  ck_assert_str_eq(str3, expected);

  free(str3);
}
END_TEST;

START_TEST(s21_insert_6) {
  char str1[] = "";
  char str2[] = "bolshenepusto";
  int index = 0;
  char *str3 = s21_insert(str1, str2, index);
  char *expected = "";

  ck_assert_str_eq(str3, expected);

  free(str3);
}
END_TEST;

START_TEST(s21_insert_7) {
  char str1[] = "odinok";
  char str2[] = "";
  int index = 2;
  char *str3 = s21_insert(str1, str2, index);
  char *expected = "odinok";

  ck_assert_str_eq(str3, expected);

  free(str3);
}
END_TEST;

START_TEST(s21_insert_strnull) {
  char *str1 = "";
  char str2[] = "odinok";
  int index = 0;
  char *str3 = s21_insert(str1, str2, index);
  char *expected = "";

  ck_assert_str_eq(str3, expected);

  free(str3);
}
END_TEST;

START_TEST(s21_trim_str_and_trimnull) {
  char str1[] = " ";
  char trim[] = " ";
  char *str2 = s21_trim(str1, trim);
  char *expected = "";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_trim_trimnull) {
  char str1[] = "juk hui";
  char trim[] = " ";
  char *str2 = s21_trim(str1, trim);
  char *expected = "juk hui";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_trim_strnull) {
  char str1[] = "";
  char trim[] = "krests povsudu";
  char *str2 = s21_trim(str1, trim);
  char *expected = "";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_trim_1) {
  char str1[] = "1213123jeinewiqiunf012390192";
  char trim[] = "1234567890";
  char *str2 = s21_trim(str1, trim);
  char *expected = "jeinewiqiunf";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_trim_2) {
  char str1[] = "1asa313as13sa3sa31sa3s13asa13sa13s";
  char trim[] = " 13as";
  char *str2 = s21_trim(str1, trim);
  char *expected = "";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_trim_3) {
  char str1[] = "123213einwf10mf012821203j20192jf";
  char trim[] = "2jf";
  char *str2 = s21_trim(str1, trim);
  char *expected = "123213einwf10mf012821203j2019";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_trim_4) {
  char str1[] = "123213einwf10mf012821203j20192jf";
  char trim[] = "123";
  char *str2 = s21_trim(str1, trim);
  char *expected = "einwf10mf012821203j20192jf";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_trim_5) {
  char str1[] = "123213einwf10mf012821203j20192jf";
  char trim[] = "12309eijf";
  char *str2 = s21_trim(str1, trim);
  char *expected = "nwf10mf0128";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_trim_6) {
  char str1[] = "123213einwf10mf012821203j20192jf";
  char trim[] = "123089ewijfmn";
  char *str2 = s21_trim(str1, trim);
  char *expected = "";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

START_TEST(s21_trim_7) {
  char str1[] = "123213einwf10mf012821203j20192jf";
  char trim[] = "123089ewijfmn";
  char *str2 = s21_trim(str1, trim);
  char *expected = "";

  ck_assert_str_eq(str2, expected);

  free(str2);
}
END_TEST;

Suite *sharp_test(void) {
  Suite *s = suite_create("\033[45mss21_sharp\033[0m");
  TCase *tc = tcase_create("s21_sharp");

  tcase_add_test(tc, s21_to_lower_strnull);
  tcase_add_test(tc, s21_to_lower_1);
  tcase_add_test(tc, s21_to_lower_2);
  tcase_add_test(tc, s21_to_lower_3);
  tcase_add_test(tc, s21_to_lower_4);
  tcase_add_test(tc, s21_to_lower_5);
  tcase_add_test(tc, s21_to_lower_6);
  tcase_add_test(tc, s21_to_upper_strnull);
  tcase_add_test(tc, s21_to_upper_1);
  tcase_add_test(tc, s21_to_upper_2);
  tcase_add_test(tc, s21_to_upper_3);
  tcase_add_test(tc, s21_to_upper_4);
  tcase_add_test(tc, s21_to_upper_5);
  tcase_add_test(tc, s21_to_upper_6);
  tcase_add_test(tc, s21_insert_strnull);
  tcase_add_test(tc, s21_insert_1);
  tcase_add_test(tc, s21_insert_2);
  tcase_add_test(tc, s21_insert_3);
  tcase_add_test(tc, s21_insert_4);
  tcase_add_test(tc, s21_insert_5);
  tcase_add_test(tc, s21_insert_6);
  tcase_add_test(tc, s21_insert_7);
  tcase_add_test(tc, s21_trim_str_and_trimnull);
  tcase_add_test(tc, s21_trim_trimnull);
  tcase_add_test(tc, s21_trim_strnull);
  tcase_add_test(tc, s21_trim_1);
  tcase_add_test(tc, s21_trim_2);
  tcase_add_test(tc, s21_trim_3);
  tcase_add_test(tc, s21_trim_4);
  tcase_add_test(tc, s21_trim_5);
  tcase_add_test(tc, s21_trim_6);
  tcase_add_test(tc, s21_trim_7);

  suite_add_tcase(s, tc);
  return s;
}