/*
 * @Author: huang123aini aiya123aini@163.com
 * @Date: 2024-07-18 10:55:25
 * @LastEditors: huang123aini aiya123aini@163.com
 * @LastEditTime: 2024-07-22 14:59:40
 * @FilePath: /CPlusPlusCode/chapter04/multi_inheritance.cpp
 */

#include <iostream>

class Base1 {
 public:
  int x;
  int y;
  virtual void function_1() { std::cout << "Base1 function()" << std::endl; }
};

class Base2 {
 public:
  int z;
  virtual void function_2() { std::cout << "Base2 function()" << std::endl; }
};

class A : public Base1, public Base2 {
 public:
  int w;
  virtual void function_3() { std::cout << "A function()" << std::endl; }
};

// 继承多个父类的情况

/**
1) 首先是基类1虚函数表指针

2) 基类1数据成员

3) 基类2虚函数表指针

4) 基类2数据成员

5) 子类数据成员

6) 子类实现基类的虚函数,并覆盖基类虚函数表中相应的函数的地址

7) 子类扩展第一个基类的虚函数表,将子类的虚函数地址存储在基类虚函数表中

8) 内存中存在2张虚函数表
 *
 */

typedef void (*func_t)(void);

int main() {
  Base1 base1;
  base1.x = 1;
  base1.y = 2;

  (((void (*)()) * ((std::int64_t*)(*((std::int64_t*)&base1)) + 0)))();
  std::cout << " sizeof(base1): " << sizeof(base1) << std::endl;
  std::cout << "base1: " << &base1 << " x: " << &(base1.x)
            << " y: " << &(base1.y) << std::endl;

  Base2 base2;
  base2.z = 3;
  (((void (*)()) * ((std::int64_t*)(*((std::int64_t*)&base2)) + 0)))();
  std::cout << " sizeof(base2): " << sizeof(base2) << std::endl;
  std::cout << "base2: " << &base2 << " z: " << &(base2.z) << std::endl;

  A a;
  a.x = 1;
  a.y = 2;
  a.z = 3;
  a.w = 4;

  std::cout << " sizeof(a): " << sizeof(a) << std::endl;
  std::cout << "a: " << &a << " x: " << &(a.x) << " y: " << &(a.y)
            << " z: " << &(a.z) << " w: " << &(a.w) << std::endl;

  (((void (*)()) * ((std::int64_t*)(*((std::int64_t*)&a)) + 0)))();
  (((void (*)()) * ((std::int64_t*)(*((std::int64_t*)&a)) + 1)))();

  // 虚函数表指针2->指向父类Base2的虚函数表
  std::int64_t* vTablePtr_Base2 = (std::int64_t*)*((std::int64_t*)&a + 2);
  std::cout << "Base2的虚函数表调用" << std::endl;
  for (int i = 0; i < 1; i++) {
    std::cout << "调用第" << i + 1 << "个虚函数：";
    ((func_t) * (vTablePtr_Base2 + i))();
  }
  return 0;
}