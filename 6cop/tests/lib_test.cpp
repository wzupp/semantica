#include "sem.h"
#include <cstdio>
#include <gtest/gtest.h>

int symbol;
extern int intvalue;
extern FILE *current_stream;
// extern std::string str;

void write_string_to_stdin(char *str) {
  current_stream = fmemopen(str, strlen(str), "r+");
}

void write_string_to_stdin(const std::string &str) {
  current_stream = fmemopen((void *)str.c_str(), str.size(), "r+");
}

TEST(YourLibTests, TestScan) {
  std::string test_string = "if ( 1 <  2 ) name ( 9 ) ;";
  write_string_to_stdin(test_string);

  symbol = scan();
  EXPECT_EQ(symbol, IF);

  symbol = scan();
  EXPECT_EQ(symbol, lbrace);

  symbol = scan();
  EXPECT_EQ(symbol, val);
  EXPECT_EQ(int(1), intvalue);

  symbol = scan();
  EXPECT_EQ(symbol, less);

  symbol = scan();
  EXPECT_EQ(symbol, val);
  EXPECT_EQ(int(2), intvalue);

  symbol = scan();
  EXPECT_EQ(symbol, rbrace);

  symbol = scan();
  EXPECT_EQ(symbol, name);

  symbol = scan();
  EXPECT_EQ(symbol, lbrace);

  symbol = scan();
  EXPECT_EQ(symbol, val);
  EXPECT_EQ(int(9), intvalue);

  symbol = scan();
  EXPECT_EQ(symbol, rbrace);

  symbol = scan();
  EXPECT_EQ(symbol, col);
}
