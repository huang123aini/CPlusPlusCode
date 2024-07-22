/*
 * @Author: huang123aini aiya123aini@163.com
 * @Date: 2024-07-22 11:20:28
 * @LastEditors: huang123aini aiya123aini@163.com
 * @LastEditTime: 2024-07-22 14:45:32
 * @FilePath: /CPlusPlusCode/chapter09/multi_inheritance_layout.cpp
 */
#include <iostream>

using namespace std;

// c++多重继承的虚函数表&内存布局

// 父类Base1 & Base2 都有虚函数并有成员变量

class Base1 {
 public:
  virtual void base1_func_1() { cout << "Base1::func_1" << endl; }
  virtual void base1_func_2() { cout << "Base1::func_2" << endl; }
  virtual void base1_func_3() { cout << "Base1::func_3" << endl; }

 public:
  int x = 1;
  int y = 2;
  int z = 3;
};

class Base2 {
 public:
  virtual void base2_func_1() { cout << "Base2::func_1" << endl; }
  virtual void base2_func_2() { cout << "Base2::func_2" << endl; }
  virtual void base2_func_3() { cout << "Base2::func_3" << endl; }

 public:
  int a = 1;
  int b = 2;
};

class A : public Base1, public Base2 {
 public:
};

typedef void (*func_t)(void);

int main(void) {
  A a;

  std::cout << "sizeof(a): " << sizeof(a) << std::endl;

  // 虚函数表指针1->指向父类Base1的虚函数表
  std::int64_t* vTablePtr_Base1 = (std::int64_t*)*(std::int64_t*)&a;
  std::cout << "Base1虚函数表指针 addr: " << &a << std::endl;

  std::cout << "Base1的虚函数表调用" << std::endl;
  for (int i = 0; i < 3; i++) {
    cout << "调用第" << i + 1 << "个虚函数：";
    ((func_t) * (vTablePtr_Base1 + i))();
  }

  std::cout << "a.x addr: " << &(a.x) << " a.y addr: " << &(a.y)
            << " a.z addr: " << &(a.z) << std::endl;

  /**
   * 虚函数表指针2->指向父类Base2的虚函数表
   * 首地址 + 3个 std::int64_t == 虚函数表1的指针长度 +
   * 3个int型Base1的成员变量和内存对齐
   */
  std::int64_t* vTablePtr_Base2 = (std::int64_t*)*((std::int64_t*)&a + 3);

  std::cout << "Base2虚函数表指针 addr: " << &a + 3 << std::endl;

  std::cout << "Base2的虚函数表调用" << std::endl;
  for (int i = 0; i < 3; i++) {
    cout << "调用第" << i + 1 << "个虚函数：";
    ((func_t) * (vTablePtr_Base2 + i))();
  }

  std::cout << "a.a addr: " << &(a.a) << " a.b addr: " << &(a.b) << std::endl;
}