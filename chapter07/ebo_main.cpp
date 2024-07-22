/*
 * @Author: huang123aini aiya123aini@163.com
 * @Date: 2024-07-19 13:53:26
 * @LastEditors: huang123aini aiya123aini@163.com
 * @LastEditTime: 2024-07-19 14:00:20
 * @FilePath: /CPlusPlusCode/chapter07/ebo_main.cpp
 */
#include <iostream>

// 空白基类最优化在（empty base optimization-EBO)

class A {};

class B : public A {
 public:
  int x;
};

int main(int argc, char* argv[]) {
  A a;
  B b;

  std::cout << "sizeof(A): " << sizeof(A) << " sizeof(B): " << sizeof(B)
            << std::endl;

  return 0;
}