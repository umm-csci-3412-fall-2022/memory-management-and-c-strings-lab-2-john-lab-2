#include <gtest/gtest.h>

#include "disemvowel.h"

TEST(Disemvowel, HandleEmptyString) {
  char* testString = disemvowel((char*) "");
  ASSERT_STREQ("", testString);
  free(testString);
}

TEST(Disemvowel, HandleNoVowels) {
  char* testString = disemvowel((char*) "pqrst");
  ASSERT_STREQ("pqrst", testString);
  free(testString);
}

TEST(Disemvowel, HandleOnlyVowels) {
  char* testString = disemvowel((char*) "aeiouAEIOUOIEAuoiea");
  ASSERT_STREQ("", testString);
  free(testString);
}

TEST(Disemvowel, HandleMorrisMinnesota) {
  char* testString = disemvowel((char*) "Morris, Minnesota");
  ASSERT_STREQ("Mrrs, Mnnst", testString);
  free(testString);
}

TEST(Disemvowel, HandlePunctuation) {
  char* testString = disemvowel((char*) "An (Unexplained) Elephant!");
  ASSERT_STREQ("n (nxplnd) lphnt!", testString);
  free(testString);
}

TEST(Disemvowel, HandleLongString) {
  char *str;
  int size;
  int i;

  size = 50000;
  str = (char*) calloc(size, sizeof(char));
  str[0] = 'x';
  str[1] = 'y';
  str[2] = 'z';
  for (i = 3; i < size-1; ++i) {
    str[i] = 'a';
  }
  str[size-1] = '\0';

  char* testString = disemvowel(str);
  ASSERT_STREQ("xyz", testString);
  free(testString);

  free(str);
}

int main(int argc, char *argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
