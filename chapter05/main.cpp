/*
 * @Author: huang123aini aiya123aini@163.com
 * @Date: 2024-07-18 15:22:41
 * @LastEditors: huang123aini aiya123aini@163.com
 * @LastEditTime: 2024-07-18 15:30:54
 * @FilePath: /CPlusPlusCode/chapter05/main.cpp
 */

#include <iostream>

// C++获取类中成员函数的函数指针

class A {
 public:
  // static member
  static void staticFunc() { std::cout << "static Func" << std::endl; }
  // nonstatic member
  void nonstaticFunc() { std::cout << "nonstatic Func" << std::endl; }
  // virtual
  virtual void virtualFunc() { std::cout << "virtual Func" << std::endl; };
};

int main() {
  A a;
  /**
   *static成员函数,取得的是该函数在内存中的实际地址，而且因为static成员是全局的，所以不能用A::限定符
   */
  void (*staticPtr)() = &A::staticFunc;

  /**
   *nonstatic成员函数 取得的是该函数在内存中的实际地址
   */
  void (A::*nonstaticPtr)() = &A::nonstaticFunc;
  /**
   * 虚函数取得的是虚函数表中的偏移值，这样可以保证能过指针调用时同样的多态效果
   */
  void (A::*virtualPtr)() = &A::virtualFunc;

  // 函数指针的使用方式
  staticPtr();
  (a.*nonstaticPtr)();
  (a.*virtualPtr)();
}
