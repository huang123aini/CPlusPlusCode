/*
 * @Author: huang123aini aiya123aini@163.com
 * @Date: 2024-07-18 09:59:12
 * @LastEditors: huang123aini aiya123aini@163.com
 * @LastEditTime: 2024-07-22 10:13:57
 * @FilePath: /CPlusPlusCode/chapter04/no_inheritance.cpp
 */
#include <iostream>

class Base {
 public:
  int x;
  int y;
  virtual void function_1() { std::cout << "Base function()" << std::endl; }
};

class A : public Base {
 public:
  int z;
  virtual void function_2() { std::cout << "Sub function()" << std::endl; }
};

/**
 *1) 首先是基类虚函数表指针

 *2) 基类数据成员

 *3) 子类数据成员

 *4) 子类实现基类的虚函数,并覆盖基类虚函数表中相应的函数的地址

 *5) 子类扩展基类的虚函数表,将子类的虚函数地址存储在基类虚函数表中

 *6) 内存中只存在一张虚函数表
 *
 */

int main() {
  Base base;
  base.x = 1;
  base.y = 2;

  (((void (*)()) * ((std::int64_t *)(*((std::int64_t *)&base)) + 0)))();
  std::cout << " sizeof(base): " << sizeof(base) << std::endl;
  std::cout << "base: " << &base << " x: " << &(base.x) << " y: " << &(base.y)
            << std::endl;

  // 虚表地址
  std::int64_t base_class_vtable_addr =
      *(std::int64_t *)*(std::int64_t *)(&base);

  A a;
  a.x = 1;
  a.y = 2;

  // 对象的首地址里存储的成员是指向虚函数表的指针
  (((void (*)()) * ((std::int64_t *)(*((std::int64_t *)&a)) + 0)))();
  (((void (*)()) * ((std::int64_t *)(*((std::int64_t *)&a)) + 1)))();
  std::cout << " sizeof(): " << sizeof(a) << std::endl;
  std::cout << "a: " << &a << " x: " << &(a.x) << " y: " << &(a.y)
            << " z: " << &(a.z) << std::endl;

  // 虚表地址
  std::int64_t a_class_vtable_addr = *(std::int64_t *)*(std::int64_t *)(&a);

  std::cout << "Base Class vTable Address: "
            << *(std::int64_t *)*(std::int64_t *)(&base)
            << " A Class vTable Address: "
            << *(std::int64_t *)*(std::int64_t *)(&a) << std::endl;

  return 0;
}