/*
 * @Author: huang123aini aiya123aini@163.com
 * @Date: 2024-08-06 15:06:23
 * @LastEditors: huang123aini aiya123aini@163.com
 * @LastEditTime: 2024-08-06 15:07:54
 * @FilePath: /CPlusPlusCode/chapter11/std_move.cpp
 */
#include <iostream>
#include <utility>

class A {
 public:
  A() { std::cout << "默认构造函数\n"; }

  A(const A&) { std::cout << "复制构造函数\n"; }

  A(A&&) noexcept { std::cout << "移动构造函数\n"; }

  A& operator=(A&& other) noexcept {
    std::cout << "移动赋值运算符\n";
    /* 将资源从"other"复制到"this", 假设这涉及转移某些资源的所有权*/
    return *this;
  }
};

int main() {
  A obj1; /* 默认构造函数 */

  A obj2 = std::move(obj1); /* 移动构造函数 */

  A obj3;
  obj3 = std::move(obj2); /* 移动赋值运算符 */
  return 0;
}