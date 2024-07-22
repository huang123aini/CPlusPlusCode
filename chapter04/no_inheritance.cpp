/*
 * @Author: huang123aini aiya123aini@163.com
 * @Date: 2024-07-18 09:59:12
 * @LastEditors: huang123aini aiya123aini@163.com
 * @LastEditTime: 2024-07-22 09:40:06
 * @FilePath: /CPlusPlusCode/chapter04/no_inheritance.cpp
 */
#include <iostream>

// 关于virtual

/**
 *不考虑继承，如果一个类中有虚函数(使用了virtual关键字)，那么该类就有一个虚函数表
 *虚函数表是属于类的，一个有虚函数的类有且只有一个虚函数表，
 *所有该类的实例化对象中都会有一个虚函数表指针去指向该类的虚函数表
 *一个类的实例要么在堆上，要么在栈上。也就是说一个类可以有很多很多个实例
 *一个类只能有一个虚函数表。在编译时，一个类的虚函数表就确定了，这也是为什么它放在了只读数据段中
 */

class Base {
 public:
  int x;
  int y;
  virtual void function() { std::cout << "Base function()" << std::endl; }
};

/**
 *1、首先是虚函数表指针,该指针是由编译器
 *定义和初始化(编译阶段，编译器在构造函数内增加代码实现)
 *2、成员函数代码存储在
 *代码段,堆上构造虚函数表，将虚成员函数的地址存储在虚函数表内
 *3、数据成员按照声明的顺序布局
 */

int main() {
  Base base;
  base.x = 1;
  base.y = 2;

  // 通过虚函数指针表->虚函数指针->虚函数
  (((void (*)()) * ((std::int64_t*)(*((std::int64_t*)&base)) + 0)))();

  std::cout << " sizeof(base): " << sizeof(base) << std::endl;

  std::cout << "base: " << &base << " x: " << &(base.x) << " y: " << &(base.y)
            << std::endl;

  std::cout << (&base) << std::endl;

  return 0;
}