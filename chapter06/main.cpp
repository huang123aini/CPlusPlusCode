/*
 * @Author: huang123aini aiya123aini@163.com
 * @Date: 2024-07-19 10:03:58
 * @LastEditors: huang123aini aiya123aini@163.com
 * @LastEditTime: 2024-07-19 10:52:14
 * @FilePath: /CPlusPlusCode/chapter06/main.cpp
 */
#include <iostream>

// c++获取虚函数表以及虚函数地址

/**
 *1、如果一个类中存在虚函数的话(使用了virtual关键字)，那么编译器就会为这个类生成一个虚函数表
 *2、虚函数表中按照每个虚函数的声明顺序存放了各个虚函数的地址
 *3、一个类只有一个虚函数表，并且存放在可读区(.rodata)
 *4、对于这个类的每个对象，编译器都会为其生成一个透明不可见的指针，这个指针就是虚函数表指针，指向虚函数表
 *5、虚函数指针位于该对象内存中的开头
 *6、如果一个类中存在虚函数，假设声明一个对象a，在32位的编译情况下，对象a的内存布局中前4个字节中就存放了虚函数表的地址。在
 *64位的编译情况下，对象a的内存布局中的前4个字节中就存放了虚函数表的地址。
 */

class A {
 public:
  int x;
  int y;
  virtual void func0() { std::cout << "func0()" << std::endl; };
  virtual void func1() { std::cout << "func1()" << std::endl; };
  virtual void func2() { std::cout << "func2()" << std::endl; };
};
int main(int argc, char *argv[]) {
  /**
   *Note:本测试用例是在64位机器
   */

  std::cout << "=================================" << std::endl;

  A a;
  std::cout << "address of a : " << &a << std::endl;

  /**
   *1、&a得到对象a的首地址
   *2、将得到的首地址强制转换成(std::int64_t*) (此指针就是虚函数表指针)
   *(如果是32位机器，则是强制转换为 int*)
   *3、再通过"*"获取指针内容（即虚函数表地址）
   */

  std::cout << "address of vtbl : " << *(std::int64_t *)(&a) << std::endl;

  /**
   *4、得到虚函数表的地址后，我们就可以得到虚函数表
   *5、得到虚函数表后，我们就可以得到虚函数表的首地址
   */

  // 虚表地址 == 虚表首地址
  std::int64_t vtable_addr = *(std::int64_t *)*(std::int64_t *)(&a);

  std::cout << "vtable_addr: " << vtable_addr << std::endl;

  /**
   *Note:虚函数表里是按照声明顺序依次存放各个虚函数地址
   */

  // 虚函数func0地址
  std::int64_t func0_addr = *(std::int64_t *)*(std::int64_t *)(&a);
  std::cout << "func0_addr: " << func0_addr << std::endl;

  // 虚函数func1地址
  std::int64_t func1_addr = *((std::int64_t *)(*(std::int64_t *)(&a)) + 1);
  std::cout << "func1_addr: " << func1_addr << std::endl;

  // 虚函数func2地址
  std::int64_t func2_addr = *((std::int64_t *)(*(std::int64_t *)(&a)) + 2);
  std::cout << "func2_addr: " << func2_addr << std::endl;

  /**
   *6、使用函数地址调用函数:((void(*)(void))faddr)()
   *第一个void指定了函数返回类型，第二个void指定了形参类型，faddr为函数地址，最后的括号中放相应参数
   */
  ((void (*)(void))func0_addr)();

  ((void (*)(void))func1_addr)();

  ((void (*)(void))func2_addr)();

  std::cout << "=================================" << std::endl;

  /**
   *7、自此我们成功验证了,对于使用了virtual关键字的类
   *可以通过对象的首地址的内容(虚函数表指针)找到虚函数表,
   *再通过虚函数表的内容获取虚函数地址，通过函数地址调用函数
   */

  /**
   *8、接下来我们验证一下一个具有虚函数的类只有一个虚函数表
   */

  A a1;
  A a2;
  std::int64_t vtable_addr_a1 = *(std::int64_t *)*(std::int64_t *)(&a1);
  std::int64_t vtable_addr_a2 = *(std::int64_t *)*(std::int64_t *)(&a2);

  std::cout << "vtabe_addr_a1: " << vtable_addr_a1
            << " vtable_addr_a2: " << vtable_addr_a2 << std::endl;

  std::cout << "=================================" << std::endl;

  return 0;
}
