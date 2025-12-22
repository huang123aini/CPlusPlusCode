/*
 * @Author: huang123aini aiya123aini@163.com
 * @Date: 2024-08-06 15:11:42
 * @LastEditors: huang123aini aiya123aini@163.com
 * @LastEditTime: 2024-08-06 15:11:47
 * @FilePath: /CPlusPlusCode/chapter11/std_forward.cpp
 */
#include <iostream>
#include <utility>

void inner(int&& x) {
  /* 带有右值引用 */
  std::cout << " RValue X: " << x << "\n";
}

void inner(const int& x) {
  /* const 左值引用 */
  std::cout << " LValue X: " << x << "\n";
}

template <typename T>
void wrapper(T&& arg) {
  /* 将 'arg' 完全按照传递给 'inner' 的方式转发 */
  inner(std::forward<T>(arg));
}

int main() {
  int x = 4;
  wrapper(x);  /* 'x' 是左值，作为左值转发 */
  wrapper(42); /* '42' 是右值，作为右值转发 */
}