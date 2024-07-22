/*
 * @Author: huang123aini aiya123aini@163.com
 * @Date: 2024-07-22 09:52:04
 * @LastEditors: huang123aini aiya123aini@163.com
 * @LastEditTime: 2024-07-22 09:55:45
 * @FilePath: /CPlusPlusCode/chapter04/no_inheritance_and_normal.cpp
 */

#include <iostream>

class Base {
 public:
  int x;
  int y;
  virtual void function() { std::cout << "Base function()" << std::endl; }
  void normal_function() { std::cout << "Base normal function. " << std::endl; }
};

int main() {
  Base base;
  base.x = 1;
  base.y = 2;

  // 通过虚函数指针表->虚函数指针->虚函数
  (((void (*)()) * ((std::int64_t*)(*((std::int64_t*)&base)) + 0)))();

  std::cout << " sizeof(base): " << sizeof(base) << std::endl;

  std::cout << "base: " << &base << " x: " << &(base.x) << " y: " << &(base.y)
            << " normal function addr: " << &Base::normal_function << std::endl;

  std::cout << (&base) << std::endl;

  return 0;
}