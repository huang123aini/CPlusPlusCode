/*
 * @Author: huang123aini aiya123aini@163.com
 * @Date: 2024-08-06 15:14:09
 * @LastEditors: huang123aini aiya123aini@163.com
 * @LastEditTime: 2024-08-06 15:15:34
 * @FilePath: /CPlusPlusCode/chapter11/std_move_forward.cpp
 */
#include <iostream>

/* 此函数接受左值引用 */
void equal(int& a) { std::cout << " int&: " << a << std::endl; }

/* 此函数接受右值引用 */
void equal(int&& a) { std::cout << "int&&: " << a << std::endl; }

/* 此函数使用 std::move 调用 equal，将参数转换为右值引用 */
template <typename T>
void move_func(T&& a) {
  equal(std::move(a));
}

/* 此函数使用 std::forward 调用 equal，保留参数的原始值类别 */
template <typename T>
void forward_func(T&& a) {
  equal(std::forward<T>(a));
}

int main() {
  int arg = 10;

  std::cout << "用 std::move() 调用 move_func..." << std::endl;
  move_func(arg); /* arg 是左值 */
  move_func(25);  /* 25 是右值 */

  std::cout << "用 std::forward() 调用 forward..." << std::endl;
  forward_func(arg); /* arg 是左值 */
  forward_func(25);  /* 25 是右值 */

  return 0;
}