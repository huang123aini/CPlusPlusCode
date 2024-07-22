/*
 * @Author: huang123aini aiya123aini@163.com
 * @Date: 2024-07-19 14:01:35
 * @LastEditors: huang123aini aiya123aini@163.com
 * @LastEditTime: 2024-07-19 14:09:27
 * @FilePath: /CPlusPlusCode/chapter07/multi_inheritance.cpp
 */
#include <iostream>

// 空白基类最优化在一些编译器上可以被用于多重继承
class A {};

class B {};

class C : public A, public B {
 public:
  int x;
};

int main(int argc, char* argv[]) {
  std::cout << "sizeof(A): " << sizeof(A) << " sizeof(B): " << sizeof(B)
            << " sizeof(C): " << sizeof(C) << std::endl;
  return 0;
}