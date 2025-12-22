/*
 * @Author: huang123aini aiya123aini@163.com
 * @Date: 2024-08-06 14:46:33
 * @LastEditors: huang123aini aiya123aini@163.com
 * @LastEditTime: 2024-08-06 14:59:42
 * @FilePath: /CPlusPlusCode/chapter11/main.cpp
 */
#include <iostream>
#include <utility>

void bar(int& lref) { std::cout << "左值引用" << std::endl; }

void bar(int&& rref) { std::cout << "右值引用" << std::endl; }

template <typename T>
void foo(T&& param) {
  bar(std::forward<T>(param));
}

int main() {
  int x = 5;

  foo(x);   // 左值引用
  foo(20);  // 右值引用

  return 0;
}
