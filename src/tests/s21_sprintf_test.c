#include "s21_test.h"

START_TEST(sprintf_test1) {
  char str[1024] = {0};
  char str1[1000] = {0};

  s21_sprintf(str, "Hello, !%f! end.", 2.458);
  sprintf(str1, "Hello, !%f! end.", 2.458);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test2) {
  char str[1000] = {0};
  char str1[1000] = {0};

  s21_sprintf(str, "Hello, !%.f! end.", 2.458);
  sprintf(str1, "Hello, !%.f! end.", 2.458);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test3) {
  char str[1000] = {0};
  char str1[1000] = {0};

  s21_sprintf(str, "Hello, !% .10d! end.", 2);
  sprintf(str1, "Hello, !% .10d! end.", 2);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test4) {
  char str[1000] = {0};
  char str1[1000] = {0};

  s21_sprintf(str, "Hello, !%.10u! end.", 223);
  sprintf(str1, "Hello, !%.10u! end.", 223);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test5) {
  char str[1000] = {0};
  char str1[1000] = {0};

  s21_sprintf(str, "Hello, !%u! end.", -223);
  sprintf(str1, "Hello, !%u! end.", -223);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test5_1) {
  char str[1000] = {0};
  char str1[1000] = {0};

  s21_sprintf(str, "Hello, !%u! end.", 223);
  sprintf(str1, "Hello, !%u! end.", 223);
  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test6) {
  char s_21str[1000] = {0};
  char str1[1000] = {0};

  s21_sprintf(s_21str, "Hello, !%-*.8u! end.", 10, -223);
  sprintf(str1, "Hello, !%-*.8u! end.", 10, -223);

  ck_assert_str_eq(s_21str, str1);
}
END_TEST;

START_TEST(sprintf_test6_1) {
  char s_21str[1000] = {0};
  char str1[1000] = {0};

  s21_sprintf(s_21str, "Hello, !% -*.8d! end.", 10, -223);
  sprintf(str1, "Hello, !% -*.8d! end.", 10, -223);
  ck_assert_str_eq(s_21str, str1);
}
END_TEST;

START_TEST(sprintf_test6_2) {
  char s_21str[1000] = {0};
  char str1[1000] = {0};

  s21_sprintf(s_21str, "Hello, !%-*.2f! end.", 10, -223.814);
  sprintf(str1, "Hello, !%-*.2f! end.", 10, -223.814);
  ck_assert_str_eq(s_21str, str1);
}
END_TEST;

START_TEST(sprintf_test7) {
  char str[1000] = {0};
  char str1[1000] = {0};

  s21_sprintf(str, "Hello, !%-*d! end.", 10, -32556);
  sprintf(str1, "Hello, !%-*d! end.", 10, -32556);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test7_1) {
  char str[1000] = {0};
  char str1[1000] = {0};

  s21_sprintf(str, "Hello, !%+*d! end.", 10, 0);
  sprintf(str1, "Hello, !%+*d! end.", 10, 0);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test7_2) {
  char str[1000] = {0};
  char str1[1000] = {0};

  s21_sprintf(str, "Hello, !%+*d! end.", 10, 5);
  sprintf(str1, "Hello, !%+*d! end.", 10, 5);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test7_3) {
  char str[1000] = {0};
  char str1[1000] = {0};

  s21_sprintf(str, "Hello, !%+*d! end.", 10, -1);
  sprintf(str1, "Hello, !%+*d! end.", 10, -1);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test7_4) {
  char str[1000] = {0};
  char str1[1000] = {0};

  s21_sprintf(str, "Hello, !%+*f! end.", 10, -324.23);
  sprintf(str1, "Hello, !%+*f! end.", 10, -324.23);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test8) {
  char str[1000] = {0};
  char str1[1000] = {0};

  s21_sprintf(str, "Hello, !%+*.10d! end.", 10, 223);
  sprintf(str1, "Hello, !%+*.10d! end.", 10, 223);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test9) {
  char str[1000] = {0};
  char str1[1000] = {0};

  s21_sprintf(str, "Hello, !%X! end.", 5435345);
  sprintf(str1, "Hello, !%X! end.", 5435345);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test10) {
  char str[1000] = {0};
  char str1[1000] = {0};

  s21_sprintf(str, "Hello, !%x! end.", 34562);
  sprintf(str1, "Hello, !%x! end.", 34562);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test11) {
  char str[1000] = {0};
  char str1[1000] = {0};

  s21_sprintf(str, "Hello, !%-*.8x! end.", 10, 34562);
  sprintf(str1, "Hello, !%-*.8x! end.", 10, 34562);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test12) {
  char str[1024] = {0};
  char str1[1000] = {0};

  s21_sprintf(str, "Hello, !%o! end.", 34562);
  sprintf(str1, "Hello, !%o! end.", 34562);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test13) {
  char str[1000] = {0};
  char str1[1000] = {0};

  s21_sprintf(str, "Hello, !%-*.3lo! end.", 12, 26426554363463);
  sprintf(str1, "Hello, !%-*.3lo! end.", 12, 26426554363463);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test14) {
  char str[1000] = {0};
  char str1[1000] = {0};

  int p = 0;

  s21_sprintf(str, "Hello, !%p! end.", &p);
  sprintf(str1, "Hello, !%p! end.", &p);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test15) {
  char str[1000] = {0};
  char str1[1000] = {0};

  char *p = s21_NULL;

  s21_sprintf(str, "Hello, !%p! end.", &p);
  sprintf(str1, "Hello, !%p! end.", &p);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test16) {
  char str[1000] = {0};
  char str1[1000] = {0};

  long double p = 0;

  s21_sprintf(str, "Hello, !%-*p! end.", 20, &p);
  sprintf(str1, "Hello, !%-*p! end.", 20, &p);

  ck_assert_str_eq(str, str1);
}
END_TEST;

START_TEST(sprintf_test17) {
  char str[1000] = {0};
  char str1[1000] = {0};

  long double p = 0;

  int s21 = s21_sprintf(str, "Hello, !%-*p! end.", 20, &p);
  int orig = sprintf(str1, "Hello, !%-*p! end.", 20, &p);

  ck_assert_str_eq(str, str1);

  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test18) {
  char str[1000] = {0};
  char str1[1000] = {0};

  long double p = 0;

  int s = 0;
  int n = 0;

  int s21 = s21_sprintf(str, "Hello, !%-*p!%n end.", 20, &p, &n);
  int orig = sprintf(str1, "Hello, !%-*p!%n end.", 20, &p, &s);

  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21, orig);
  ck_assert_int_eq(n, s);
}
END_TEST;

START_TEST(sprintf_test19) {
  char str[1000] = {0};
  char str1[1000] = {0};

  int s21 = s21_sprintf(str, "Hello, !%.4f! end.", 2.00234);
  int orig = sprintf(str1, "Hello, !%.4f! end.", 2.00234);

  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test19_1) {
  char str[1000] = {0};
  char str1[1000] = {0};

  int s21 = s21_sprintf(str, "Hello, !%.15f! end.", 2.764);
  int orig = sprintf(str1, "Hello, !%.15f! end.", 2.764);

  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test19_2) {
  char str[1000] = {0};
  char str1[1000] = {0};

  int s21 = s21_sprintf(str, "Hello, !% .15f! end.", 2.0000000764);
  int orig = sprintf(str1, "Hello, !% .15f! end.", 2.0000000764);

  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test19_3) {
  char str[1000] = {0};
  char str1[1000] = {0};

  int s21 = s21_sprintf(str, "Hello, !%.2f! end.", 4356.325);
  int orig = sprintf(str1, "Hello, !%.2f! end.", 4356.325);

  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test20) {
  char str[1000] = {0};
  char str1[1000] = {0};

  int s21 = s21_sprintf(str, "Hello, !%.0e! end.", 53686.6243);
  int orig = sprintf(str1, "Hello, !%.0e! end.", 53686.6243);

  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test21) {
  char str[1000] = {0};
  char str1[1000] = {0};

  int s21 = s21_sprintf(str, "Hello, !% .4e! end.", 356856924.45325);
  int orig = sprintf(str1, "Hello, !% .4e! end.", 356856924.45325);

  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test22) {
  char str[1000] = {0};
  char str1[1000] = {0};

  int s21 =
      s21_sprintf(str, "Hello, !%.15e! end.", 356856924.00000000000000002);
  int orig = sprintf(str1, "Hello, !%.15e! end.", 356856924.00000000000000002);

  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test23) {
  char str[1000] = {0};
  char str1[1000] = {0};

  int s21 = s21_sprintf(str, "Hello, !% .14E! end.", -0.000000000000002);
  int orig = sprintf(str1, "Hello, !% .14E! end.", -0.000000000000002);

  ck_assert_str_eq(str, str1);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test24) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%.6g! end.", 4734.243522532);
  int orig = sprintf(orig_str, "Hello, !%.6g! end.", 4734.243522532);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test24_1) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%.2G! end.", 4734.243522532);
  int orig = sprintf(orig_str, "Hello, !%.2G! end.", 4734.243522532);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test24_2) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%g! end.", 23.345353882634);
  int orig = sprintf(orig_str, "Hello, !%g! end.", 23.345353882634);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test24_3) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !% g! end.", 0.0025);
  int orig = sprintf(orig_str, "Hello, !% g! end.", 0.0025);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test24_4) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%.g! end.", 34.2342345);
  int orig = sprintf(orig_str, "Hello, !%.g! end.", 34.2342345);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test24_5) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%.g! end.", 3.02);
  int orig = sprintf(orig_str, "Hello, !%.g! end.", 3.02);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test25) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  char test[] = "HELLO EVERYONE I\'M COOL";

  int s21 = s21_sprintf(s21_str, "Hello, !%.7s! end.", test);
  int orig = sprintf(orig_str, "Hello, !%.7s! end.", test);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test26) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  char test[] = "HELLO EVERYONE I\'M COOL";

  int s21 = s21_sprintf(s21_str, "Hello, !%s! end.", test);
  int orig = sprintf(orig_str, "Hello, !%s! end.", test);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test27) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  char test[] = "HELLO EVERYONE I\'M COOL";

  int s21 = s21_sprintf(s21_str, "Hello, !%.0s! end.", test);
  int orig = sprintf(orig_str, "Hello, !%.0s! end.", test);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test28) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  char test[] = "HELLO EVERYONE I\'M COOL";

  int s21 = s21_sprintf(s21_str, "Hello, !%-.s! end.", test);
  int orig = sprintf(orig_str, "Hello, !%-.s! end.", test);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test29) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  char test[] = "werjweklrj345u3409ruwe4yisadsadasdasdasdasdasdi";

  int s21 = s21_sprintf(s21_str, "Hello, !%s! end.", test);
  int orig = sprintf(orig_str, "Hello, !%s! end.", test);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test30) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !% .d! end.", 3);
  int orig = sprintf(orig_str, "Hello, !% .d! end.", 3);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test31) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !% -*.8g! end.", 20, 32342.142424);
  int orig = sprintf(orig_str, "Hello, !% -*.8g! end.", 20, 32342.142424);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test32) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !% *.*e! end.", 20, 8, 32342.2);
  int orig = sprintf(orig_str, "Hello, !% *.*e! end.", 20, 8, 32342.2);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test33) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !% *.8d! end.", 20, -32342);
  int orig = sprintf(orig_str, "Hello, !% *.8d! end.", 20, -32342);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test34) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !% 020.8g! end.", 32342.758);
  int orig = sprintf(orig_str, "Hello, !% 020.8g! end.", 32342.758);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test35) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%.12g! end.", 32342.758);
  int orig = sprintf(orig_str, "Hello, !%.12g! end.", 32342.758);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test36) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%0*i! end.", 10, 74525);
  int orig = sprintf(orig_str, "Hello, !%0*i! end.", 10, 74525);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test37) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%#.0f! end.", 74525.);
  int orig = sprintf(orig_str, "Hello, !%#.0f! end.", 74525.);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test38) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%#.0e! end.", 74525.);
  int orig = sprintf(orig_str, "Hello, !%#.0e! end.", 74525.);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test39) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%#.0E! end.", 74525.);
  int orig = sprintf(orig_str, "Hello, !%#.0E! end.", 74525.);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test40) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%#.f! end.", 74525.234);
  int orig = sprintf(orig_str, "Hello, !%#.f! end.", 74525.234);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test41) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%#x! end.", 74524);
  int orig = sprintf(orig_str, "Hello, !%#x! end.", 74524);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test42) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%#X! end.", 74524);
  int orig = sprintf(orig_str, "Hello, !%#X! end.", 74524);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test43) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%#o! end.", 74524);
  int orig = sprintf(orig_str, "Hello, !%#o! end.", 74524);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test44) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%#.3o! end.", 74524);
  int orig = sprintf(orig_str, "Hello, !%#.3o! end.", 74524);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test45) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%c! end.", 'w');
  int orig = sprintf(orig_str, "Hello, !%c! end.", 'w');

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test46) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%u! end.", 0);
  int orig = sprintf(orig_str, "Hello, !%u! end.", 0);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test47) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%.0s! end.", "privet!!!]");
  int orig = sprintf(orig_str, "Hello, !%.0s! end.", "privet!!!]");

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test48) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%.0s! end.", "privet!!!]");
  int orig = sprintf(orig_str, "Hello, !%.0s! end.", "privet!!!]");

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test49) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%#10.3g! end.", 644.2345);
  int orig = sprintf(orig_str, "Hello, !%#10.3g! end.", 644.2345);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test50) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};
  unsigned short int a = 3;

  int s21 = s21_sprintf(s21_str, "Hello, !%.hu! end.", a);
  int orig = sprintf(orig_str, "Hello, !%.hu! end.", a);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test51) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};
  short int a = 3;

  int s21 = s21_sprintf(s21_str, "Hello, !% .hd! end.", a);
  int orig = sprintf(orig_str, "Hello, !% .hd! end.", a);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test52) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%.0s! end.", "");
  int orig = sprintf(orig_str, "Hello, !%.0s! end.", "");

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

// START_TEST(sprintf_test53) {
//     char s21_str[1024] = {0};
//     char orig_str[1024] = {0};
//     wchar_t a = L'н';

//     int s21 = s21_sprintf(s21_str, "Hello, !%lc! end.", a);
//     int orig = sprintf(orig_str, "Hello, !%lc! end.", a);

//     ck_assert_str_eq(s21_str, orig_str);
//     ck_assert_int_eq(s21, orig);
// }
// END_TEST;

START_TEST(sprintf_test54) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%.0f! end.", 876.568);
  int orig = sprintf(orig_str, "Hello, !%.0f! end.", 876.568);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test55) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%.5g! end.", 876.98778);
  int orig = sprintf(orig_str, "Hello, !%.5g! end.", 876.98778);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test56) {
  char s21_str[1024] = {0};
  char orig_str[1024] = {0};

  int s21 = s21_sprintf(s21_str, "Hello, !%.1f! end.", 999.9999);
  int orig = sprintf(orig_str, "Hello, !%.1f! end.", 999.9999);

  ck_assert_str_eq(s21_str, orig_str);
  ck_assert_int_eq(s21, orig);
}
END_TEST;

START_TEST(sprintf_test57) {
  char str1[500] = {0};
  char str2[500] = {0};
  char format[] = "%.5g";
  double hex = 0;

  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test58) {
  char str1[500] = {0};
  char str2[500] = {0};
  char format[] = "%LG %g %G %Lg %.5g";
  long double hex = 0.000005;
  double hex1 = 41.1341;
  double hex2 = 848.9000;
  long double hex3 = 0.0843;
  double hex4 = 0.0005;
  double hex5 = 0.8481481;

  s21_sprintf(str1, format, hex, hex1, hex2, hex3, hex4, hex5);
  sprintf(str2, format, hex, hex1, hex2, hex3, hex4, hex5);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test59) {
  char str1[512] = {0};
  char str2[512] = {0};
  char format[] = "%5.8g";
  double hex = 0.0000005;

  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test60) {
  char str1[512] = {0};
  char str2[512] = {0};
  char format[] = "%.g";
  double hex = 0.0004;

  s21_sprintf(str1, format, hex);
  sprintf(str2, format, hex);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test61) {
  char str1[512] = {0};
  char str2[512] = {0};
  char format[] = "% s% c";

  s21_sprintf(str1, format, "", 'f');
  sprintf(str2, format, "", 'f');

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test62) {
  char str1[512] = {0};
  char str2[512] = {0};
  char format[] = "%-11.11li%-35.5lu%-3.5ld%33.15Lf";
  long double k = 333.33213;

  s21_sprintf(str1, format, 66666666666, 5555555555, 44444444444, k);
  sprintf(str2, format, 66666666666, 5555555555, 44444444444, k);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test63) {
  char str1[512] = {0};
  char str2[512] = {0};
  char format[] = "%7.4s";

  s21_sprintf(str1, format, "aboba floppa");
  sprintf(str2, format, "aboba floppa");

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test64) {
  char str1[512] = {0};
  char str2[512] = {0};

  s21_sprintf(
      str1, "%#3.*X %#3x %-7.*X %#-1.8X %4.3X %#2.15x %*.*X %*.1X %3X %-1X", 3,
      -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41, -41, 33);
  sprintf(str2, "%#3.*X %#3x %-7.*X %#-1.8X %4.3X %#2.15x %*.*X %*.1X %3X %-1X",
          3, -126714, 4444444, 0, 6423235, 0, 666, 999, 13, 5, -419, 9, 41, -41,
          33);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test66) {
  char str1[512] = {0};
  char str2[512] = {0};
  char format[] = "%+2.1c %+4.2d %+5.4i !%+10.2f% +55.55s%+1.1u";

  s21_sprintf(str1, format, 'f', 21, 42, 666.666,
              "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11);
  sprintf(str2, format, 'f', 21, 42, 666.666,
          "Lorem ipsum dolor sit amet. Aut quam ducimus.", 11);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test67) {
  char str1[512] = {0};
  char str2[512] = {0};
  char *format = "% .0f %.lf %Lf %f %lf %Lf";
  float val = 0;
  double val1 = 0;
  long double val2 = 3515315.153151;
  float val3 = 5.5;
  double val4 = 9851.51351;
  long double val5 = 95919539159.53151351131;

  s21_sprintf(str1, format, val, val1, val2, val3, val4, val5);
  sprintf(str2, format, val, val1, val2, val3, val4, val5);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test68) {
  char str1[512] = {0};
  char str2[512] = {0};

  char *format = "%p";
  char *ptr = s21_NULL;
  s21_sprintf(str1, format, ptr);
  sprintf(str2, format, ptr);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test69) {
  char str1[512] = {0};
  char str2[512] = {0};
  char *format = "%.15LE";
  long double val = 4134121;

  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test70) {
  char str1[512] = {0};
  char str2[512] = {0};

  char *format = "!% -5c!";
  char val = 'c';

  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test71) {
  char str1[512] = {0};
  char str2[512] = {0};

  char *format = "%-5.51o";
  int val = 14140;

  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test72) {
  char str1[512] = {0};
  char str2[512] = {0};

  char *format = "!%.0d!";
  int val = 0;

  s21_sprintf(str1, format, val);
  sprintf(str2, format, val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test73) {
  char str1[512] = {0};
  char str2[512] = {0};

  char format[] = "%0.*i %d %4.*i %+013d %d";
  int val = 69;

  s21_sprintf(str1, format, 5, val, -10431, 13, 5311, -1, -581813581);
  sprintf(str2, format, 5, val, -10431, 13, 5311, -1, -581813581);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test74) {
  char str1[512] = {0};
  char str2[512] = {0};

  s21_sprintf(str1, "12345%c789", 0);

  sprintf(str2, "12345%c789", 0);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test76) {
  char str1[200] = {0};
  char str2[200] = {0};
  char *str3 = "%- 15u!%- 15u sdsad %- u";
  unsigned int val = -3231;
  unsigned int val2 = -3231;
  unsigned int val3 = 3231;

  sprintf(str1, str3, val, val2, val3);
  s21_sprintf(str2, str3, val, val2, val3);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test77) {
  char str1[200] = {0};
  char str2[200] = {0};
  char *str3 = "!%3.u!";
  unsigned int val = 0;

  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test78) {
  char str1[1024] = {0};
  char str2[1024] = {0};
  char *str3 =
      "%0.0s %1.0s %2.0s %3.0s %5.0s %6.0s %7.0s %0.3s %0.7s %3.2s %3.7s %7.3s";
  char *val = NULL;

  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val, val, val,
              val);
  sprintf(str1, str3, val, val, val, val, val, val, val, val, val, val, val,
          val);

  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test79) {
  char str1[100] = {0};
  char str2[100] = {0};
  char *str3 = "%s %s %s %% %d";
  char *val = "This";
  char *val2 = "\0";
  int val3 = 65;
  char *val4 = "string";

  sprintf(str1, str3, val, val2, val4, val3);
  s21_sprintf(str2, str3, val, val2, val4, val3);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test80) {
  char str1[200] = {0};
  char str2[200] = {0};
  char *str3 = "!% s! !% 3.s! !% 5.7s! !% 10s! !%.s!";
  char *val = "WHAT IS THIS";
  char *val2 = "i don't care anymore, really";
  char *val3 = "PPAP";
  char *val4 = "I don't feel so good";
  char *val5 = "What is lovin'?!";

  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test81) {
  char str1[100] = {0};
  char str2[100] = {0};
  char *str3 = "Test %ls Test2";
  wchar_t *val = L"3wtf80";

  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test81_1) {
  char str1[100] = {0};
  char str2[100] = {0};
  char *str3 = "Test %.2ls Test2";
  wchar_t *val = L"3whjkhgjksh";

  sprintf(str1, str3, val);
  s21_sprintf(str2, str3, val);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test82) {
  char str1[200] = {0};
  char str2[200] = {0};
  char *str3 = "%*.*p TEST %.*p Lololol %.*p";

  char *val3 = "9193112312312";
  char *val4 = "32311";
  char *val5 = "WTF cmon";

  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  int ast6 = 18;

  sprintf(str1, str3, ast3, ast4, val3, ast5, val4, ast6, val5);
  s21_sprintf(str2, str3, ast3, ast4, val3, ast5, val4, ast6, val5);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test83) {
  char str1[200] = {0};
  char str2[200] = {0};
  char *str3 = "%p Test %3.p Test %5.7p TEST %10p %#p %-p %+p %.p % .p";
  char *val = 0;

  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test84) {
  char str1[200] = {0};
  char str2[200] = {0};
  char *str3 = "%#o Test %#3o Test %#5.7o TEST %#.7o Oof %#.o";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;

  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test85) {
  char str1[200] = {0};
  char str2[200] = {0};
  char *str3 = "%o Test %3.o Test %5.7o TEST %10o %#o %-o %+o %.o % .o";
  int val = 0;

  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test86) {
  char str1[200] = {0};
  char str2[200] = {0};
  char *str3 = "%i Test !%3.i!";
  int val = 0;

  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val, val);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test87) {
  char str1[200] = {0};
  char str2[200] = {0};
  char *str3 = "%i Test %3.i Test %5.7i TEST %10i %#i %-i %+i !%.i! !% .i!";
  int val = 0;

  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val, val);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test88) {
  char str1[200] = {0};
  char str2[200] = {0};
  char *str3 = "%#X Test %#3X Test %#5.7X TEST %#.7X Oof %#.X";
  int val = 32;
  int val2 = 8899;
  int val3 = 91918;
  int val4 = 32311;
  int val5 = 8894;

  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test89) {
  char str1[200] = {0};
  char str2[200] = {0};
  char *str3 = "%X Test %3.X Test %5.7X TEST %10X %#X %-X %+X %.X % .X";
  int val = 0;

  sprintf(str1, str3, val, val, val, val, val, val, val, val, val);
  s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test90) {
  char str1[400] = {0};
  char str2[400] = {0};
  char *str3 = "test: %-+.1Lf! test: %- .2Lf! test: %-0.3Lf!";
  long double num = -0.999999;

  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test91) {
  char str1[400] = {0};
  char str2[400] = {0};
  char *str3 = "test: %25.5Lf! test: %Lf! test: %-50Lf!";
  long double num = -9325781235683689.;

  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test92) {
  char str1[400] = {0};
  char str2[400] = {0};
  char *str3 = "test: %+ 0Lf! test: %060Lf! test: %.15Lf!";
  long double num = -93257812356836.;

  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test93) {
  char str1[400] = {0};
  char str2[400] = {0};
  char *str3 = "test: %+ 0Lf! test: %.6Lf! test: %.15Lf!";
  long double num = 82363107597385858.6495633;

  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test94) {
  char str1[400] = {0};
  char str2[400] = {0};
  char *str3 = "test: %+ 0Lf! test: %.6Lf! test: %.15Lf!";
  long double num = 82363107597385.6495633;

  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test95) {
  char str1[400] = {0};
  char str2[400] = {0};
  char *str3 = "!%+ 25.15Lf! test: !% +40.15Lf!";
  long double num = 278.723786;

  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test96) {
  char str1[400] = {0};
  char str2[400] = {0};
  char *str3 = "test: %- 010.2f! test: %- 025.7f test: %- 18.4f!";
  double num = -947.6785643;

  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test97) {
  char str1[200] = {0};
  char str2[200] = {0};
  char *str3 = "%0d Test %06i Test %05.7i TEST %0.7i Oof %0.i";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -8894;

  sprintf(str1, str3, val, val2, val3, val4, val5);
  s21_sprintf(str2, str3, val, val2, val3, val4, val5);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test98) {
  char str1[200] = {0};
  char str2[200] = {0};
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %#5.14g!";
  double num = 0.0000756589367;

  sprintf(str1, str3, num, num, num, num, num);
  s21_sprintf(str2, str3, num, num, num, num, num);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test100) {
  char str1[400] = {0};
  char str2[400] = {0};
  char *str3 = "test: %Lg!\ntest: %Lg!\n";
  long double num = 0;
  long double num1 = 1.;

  sprintf(str1, str3, num, num1);
  s21_sprintf(str2, str3, num, num1);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test101) {
  char str1[400] = {0};
  char str2[400] = {0};
  char *str3 = "test: %+.15g! test: !%+16g! test: %+ 13.5g!";
  double num = 0.00000235300;

  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test102) {
  char str1[400] = {0};
  char str2[400] = {0};
  char *str3 = "test: %.6Lg! test: %.Lg!";
  long double num = 9999.999999;

  sprintf(str1, str3, num, num);
  s21_sprintf(str2, str3, num, num);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test103) {
  char str1[400] = {0};
  char str2[400] = {0};
  char *str3 = "test: %.1Lg! test: %.2Lg! test: %.3Lg!";
  long double num = 9999.999999;

  sprintf(str1, str3, num, num, num);
  s21_sprintf(str2, str3, num, num, num);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_test104) {
  char str1[200] = {0};
  char str2[200] = {0};
  char *str3 = "%g TEST %.g TEST %4g TEST %4.g TEST %5.10g!";
  double num = 573429.56589367;

  sprintf(str1, str3, num, num, num, num, num);
  s21_sprintf(str2, str3, num, num, num, num, num);

  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *s21_sprintf_test(void) {
  Suite *s = suite_create("\033[45ms21_sprintf\033[0m");

  TCase *tc = tcase_create("21_sprintf_test");

  tcase_add_test(tc, sprintf_test1);
  tcase_add_test(tc, sprintf_test2);
  tcase_add_test(tc, sprintf_test3);
  tcase_add_test(tc, sprintf_test4);
  tcase_add_test(tc, sprintf_test5);
  tcase_add_test(tc, sprintf_test5_1);
  tcase_add_test(tc, sprintf_test6);
  tcase_add_test(tc, sprintf_test6_1);
  tcase_add_test(tc, sprintf_test6_2);
  tcase_add_test(tc, sprintf_test7);
  tcase_add_test(tc, sprintf_test7_1);
  tcase_add_test(tc, sprintf_test7_2);
  tcase_add_test(tc, sprintf_test7_3);
  tcase_add_test(tc, sprintf_test7_4);
  tcase_add_test(tc, sprintf_test8);
  tcase_add_test(tc, sprintf_test9);
  tcase_add_test(tc, sprintf_test10);
  tcase_add_test(tc, sprintf_test11);
  tcase_add_test(tc, sprintf_test12);
  tcase_add_test(tc, sprintf_test13);
  tcase_add_test(tc, sprintf_test14);
  tcase_add_test(tc, sprintf_test15);
  tcase_add_test(tc, sprintf_test16);
  tcase_add_test(tc, sprintf_test17);
  tcase_add_test(tc, sprintf_test18);
  tcase_add_test(tc, sprintf_test19);
  tcase_add_test(tc, sprintf_test19_1);
  tcase_add_test(tc, sprintf_test19_2);
  tcase_add_test(tc, sprintf_test19_3);
  // TIMEOUT
  tcase_add_test(tc, sprintf_test20);
  tcase_add_test(tc, sprintf_test21);
  tcase_add_test(tc, sprintf_test22);
  tcase_add_test(tc, sprintf_test23);
  tcase_add_test(tc, sprintf_test24);
  tcase_add_test(tc, sprintf_test24_1);
  tcase_add_test(tc, sprintf_test24_2);
  tcase_add_test(tc, sprintf_test24_3);
  tcase_add_test(tc, sprintf_test24_4);
  tcase_add_test(tc, sprintf_test24_5);
  // TIMEOUT
  tcase_add_test(tc, sprintf_test25);
  tcase_add_test(tc, sprintf_test26);
  tcase_add_test(tc, sprintf_test27);
  tcase_add_test(tc, sprintf_test28);
  tcase_add_test(tc, sprintf_test29);
  tcase_add_test(tc, sprintf_test30);
  tcase_add_test(tc, sprintf_test31);
  tcase_add_test(tc, sprintf_test32);
  tcase_add_test(tc, sprintf_test33);
  tcase_add_test(tc, sprintf_test34);
  tcase_add_test(tc, sprintf_test35);
  tcase_add_test(tc, sprintf_test36);
  tcase_add_test(tc, sprintf_test37);
  tcase_add_test(tc, sprintf_test38);
  tcase_add_test(tc, sprintf_test39);
  tcase_add_test(tc, sprintf_test40);
  tcase_add_test(tc, sprintf_test41);
  tcase_add_test(tc, sprintf_test42);
  tcase_add_test(tc, sprintf_test43);
  tcase_add_test(tc, sprintf_test44);
  tcase_add_test(tc, sprintf_test45);
  tcase_add_test(tc, sprintf_test46);
  tcase_add_test(tc, sprintf_test47);
  tcase_add_test(tc, sprintf_test48);
  tcase_add_test(tc, sprintf_test49);
  tcase_add_test(tc, sprintf_test50);
  tcase_add_test(tc, sprintf_test51);
  tcase_add_test(tc, sprintf_test52);
  // tcase_add_test(tc, sprintf_test53);
  // round test
  tcase_add_test(tc, sprintf_test54);
  tcase_add_test(tc, sprintf_test55);
  tcase_add_test(tc, sprintf_test56);
  // round test
  tcase_add_test(tc, sprintf_test57);
  tcase_add_test(tc, sprintf_test58);
  tcase_add_test(tc, sprintf_test59);
  tcase_add_test(tc, sprintf_test60);
  tcase_add_test(tc, sprintf_test61);
  tcase_add_test(tc, sprintf_test62);
  tcase_add_test(tc, sprintf_test63);
  tcase_add_test(tc, sprintf_test64);
  tcase_add_test(tc, sprintf_test66);
  tcase_add_test(tc, sprintf_test67);
  tcase_add_test(tc, sprintf_test68);
  tcase_add_test(tc, sprintf_test69);
  tcase_add_test(tc, sprintf_test70);
  tcase_add_test(tc, sprintf_test71);
  tcase_add_test(tc, sprintf_test72);
  tcase_add_test(tc, sprintf_test73);
  tcase_add_test(tc, sprintf_test74);
  tcase_add_test(tc, sprintf_test76);
  tcase_add_test(tc, sprintf_test77);
  tcase_add_test(tc, sprintf_test78);
  tcase_add_test(tc, sprintf_test79);
  tcase_add_test(tc, sprintf_test80);
  tcase_add_test(tc, sprintf_test81);
  tcase_add_test(tc, sprintf_test81_1);
  tcase_add_test(tc, sprintf_test82);
  tcase_add_test(tc, sprintf_test83);
  tcase_add_test(tc, sprintf_test84);
  tcase_add_test(tc, sprintf_test85);
  tcase_add_test(tc, sprintf_test86);
  tcase_add_test(tc, sprintf_test87);
  tcase_add_test(tc, sprintf_test88);
  tcase_add_test(tc, sprintf_test89);
  tcase_add_test(tc, sprintf_test90);
  tcase_add_test(tc, sprintf_test91);
  tcase_add_test(tc, sprintf_test92);
  tcase_add_test(tc, sprintf_test93);
  tcase_add_test(tc, sprintf_test94);
  tcase_add_test(tc, sprintf_test95);
  tcase_add_test(tc, sprintf_test96);
  tcase_add_test(tc, sprintf_test97);
  tcase_add_test(tc, sprintf_test98);
  tcase_add_test(tc, sprintf_test100);
  tcase_add_test(tc, sprintf_test101);
  tcase_add_test(tc, sprintf_test102);
  tcase_add_test(tc, sprintf_test103);
  tcase_add_test(tc, sprintf_test104);

  suite_add_tcase(s, tc);
  return s;
}
