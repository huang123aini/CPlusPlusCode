/*
 * @Author: huang123aini aiya123aini@163.com
 * @Date: 2024-07-19 14:30:13
 * @LastEditors: huang123aini aiya123aini@163.com
 * @LastEditTime: 2024-07-22 09:39:18
 * @FilePath: /CPlusPlusCode/chapter08/main.cpp
 */

#include <iostream>

// c++类普通成员函数

/**
 * 1、c++语言设计的时候有一个要求：要求对这种普通成员函数的调用不应该比全局函数效率差.
 * 2、编译器内部实际上是将对成员函数func()的调用转换成了对全局函数的调用.
 * 3、成员函数有独立的内存地址，并且成员函数的地址，是在编译期完成确定
 * 4、成员方法存储在进程的文本段，添加成员方法不会改变类实例对象的内存布局大小，它们也不占用对象实例的内存空间
 */

class A {
 public:
  int x = 0;
  // 普通成员函数
  void func(int n) {
    x += n;
    std::cout << "func is call." << std::endl;
  }
};

// 全局函数
void global_func(A* a, int n) {
  a->x += n;
  std::cout << "global func is call." << std::endl;
}

int main(int argc, char* argv[]) {
  /********************************************************/
  A a;
  // 调用普通成员函数
  a.func(1);

  std::cout << "func address: " << &A::func << std::endl;

  // 调用全局函数
  global_func(&a, 1);

  /******************************************************/

  /**
   *1、从编译器的角度看，编译器就是把普通函数当成全局函数来调用
   *2、编译器额外增加了一个叫this的形参，是个指针，指向的其实就是生成的对象
   *3、常规成员变量的存取，都通过this形参来进行
   */

  /*


  //从编译器角度看,会在普通函数的头部参数添加一个this指针，用于指向生成的对象
  void func(A *const this, int n) {
        this->x + n;
  }
  */

  /*******************************************************/

  // 普通成员函数会占用对象内存吗？

  A a1;
  std::cout << "sizeof(a1): " << sizeof(a1) << std::endl;

  return 0;
}