
//构造函数和初始化列表

//Note:初始化列表只能用于构造函数

/**
 *1、在类的实现中,构造函数体类的"初始化"实际上是赋值，而不是初始化.
 *2、也就是说，当代码运行到构造函数内部时，初始化列表已经执行完了，相当于先初始化一遍，然后又赋值一遍，重复计算，浪费效率
 *3、因此应该优先使用初始化列表
*/

/**
 *当没有默认的无参构造函数时，就一定会使用初始化列表。
 *why?
 *
*/

/**
 *1、 创建派生类对象时，程序首先调用基类构造函数，然后调用派生类构造函数。
 *2、 基类构造函数负责初始化继承的数据成员，派生类构造函数主要用于初始化新增的数据成员。
 *3、 派生类构造函数总是需要调用一个基类的构造函数。当基类没有默认的构造函数时，就必须显示指明调用哪一个构造函数。
 *4、 在继承关系中，必须显示的在初始化列表中对基类初始化，因为只有基类初始化完成后，才能进行子类初始化，而当进入子类构造函数内部时，子类初始化已经完成。
*/

//C++在创建类对象的时候需要经过两个阶段: 分配空间(Allocation) & 初始化(Initialization)

#include <iostream>

class Base {
  public:
    Base(int value) { 
      value_ = value;
      std::cout << "constructor Base(int value) " << std::endl;
    }
  private:
    int value_;
};

/**
 //不显示调用Base的构造函数，编译会报错
 class Child: public Base {
  public:
    Child() {
      value_ = 0;
      std::cout << "constructor Child() " << std::endl;
    }
  private:
    int value_;  
};
*/

//在初始化列表中显示调用Base的构造函数编译成功
class Child: public Base {
  public:
    Child():Base(1) {
      value_ = 0;
      std::cout << "constructor Child() " << std::endl;
    }
  private:
    int value_;  
};

int main(int argc, char *argv[]) {
  Child child;
  return 0;
}