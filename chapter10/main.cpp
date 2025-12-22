/*
 * @Author: huang123aini aiya123aini@163.com
 * @Date: 2024-08-06 09:35:41
 * @LastEditors: huang123aini aiya123aini@163.com
 * @LastEditTime: 2024-08-06 10:06:27
 * @FilePath: /CPlusPlusCode/chapter10/main.cpp
 */
#include <iostream>

struct A {
  char c1;
  char c2;
  int i;
  double d;
};

struct B {
  char c1;
  int i;
  char c2;
  double d;
};

// size = 2 bytes, alignment = 1-byte, address can be divisible by 1
struct S1 {
  char m1;  // 1-byte
  char m2;  // 1-byte
};

// size = 4 bytes, alignment = 2-byte, address can be divisible by 2
struct S2 {
  char m1;   // 1-byte
             // padding 1-byte space here
  short m2;  // 2-byte
};

// size = 8 bytes, alignment = 4-byte, address can be divisible by 4
struct S3 {
  char m1;  // 1-byte
            // padding 3-byte space here
  int m2;   // 4-byte
};

// size = 16 bytes, alignment = 8-byte, address can be divisible by 8
struct S4 {
  char m1;    // 1-byte
              // padding 7-byte space here
  double m2;  // 8-byte
};

// size = 16 bytes, alignment = 8-byte, address can be divisible by 8
struct S5 {
  char m1;    // 1-byte
              // padding 3-byte space here
  int m2;     // 4-byte
  double m3;  // 8-byte
};

// size = 24 bytes, alignment = 8-byte, address can be divisible by 8
struct S6 {
  char m1;    // 1-byte
              // padding 7-byte space here
  double m2;  // 8-byte

  int m3;    // 4-byte
  short m4;  // 2-byte
             // paddintg 2-byte
};

int main() {
  std::cout << "结构体A所占内存大小为:" << sizeof(A) << std::endl;
  std::cout << "结构体B所占内存大小为:" << sizeof(B) << std::endl;

  std::cout << "结构体S6所占内存大小为:" << sizeof(S6) << std::endl;

  return 0;
}