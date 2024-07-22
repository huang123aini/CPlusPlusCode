/*
 * @Author: huang123aini aiya123aini@163.com
 * @Date: 2024-07-19 13:34:19
 * @LastEditors: huang123aini aiya123aini@163.com
 * @LastEditTime: 2024-07-19 13:50:41
 * @FilePath: /CPlusPlusCode/chapter07/main.cpp
 */

#include <iostream>

// c++空类占位问题

/**
 *1、在C++中空类会占一个字节，这是为了让对象的实例能够相互区别
 *2、空类同样可以被实例化，并且每个实例在内存中都有独一无二的地址
 *3、编译器会给空类隐含加上一个字节，这样空类实例化之后就会拥有独一无二的内存地址
 */

// Note: 当该空白类作为基类时，该类的大小就优化为0了，这就是所谓的空白基类最优化

class A {};

int main(int argc, char* argv[]) {
  A a1, a2;
  std::cout << "sizeof(A): " << sizeof(A) << " sizeof(a1): " << sizeof(a1)
            << " sizeof(a2): " << sizeof(a2) << std::endl;

  std::cout << "a1 address: " << &a1 << " a2 address: " << &a2 << std::endl;

  return 0;
}
