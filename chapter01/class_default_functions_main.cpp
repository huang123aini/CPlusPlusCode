/* 类的默认函数

只声明一个空类，不做任何事情的话，编译器会自动生成一个默认构造函数，一个默认拷贝构造函数，一个默认重载赋值操作符函数和一个默认析构函数。 这些函数只有在第一次被调用的时候，才会被编译器创建，当然这几个生成的默认函数的实现就是什么都不做，所有这些函数都是inline和public的。


class A{
public:
  //默认构造函数
  A();
  
  //默认拷贝构造函数
  A(const A&);
  
  //默认析构函数
  ~();
  
  //默认重载赋值运算符函数
  A& operator = (const A&);
  
  //默认重载取址运算符函数
  A* operator & ();
  
  默认重载取址运算符 const函数
  const A* operator & () const;
  
  //默认移动构造函数
  A(A&&);
  
  //默认重载移动赋值操作符
  A& operator = (const A&&);
  
};


构造函数的作用是对对象进行初始化。  在堆上new一个对象，或者在栈上定义一个临时对象，会自动调用对象的构造函数。
有初始化列表 & 构造函数体内赋值两种方式。

初始化列表在初始化时更高效(每个成员在初始化列表中只能出现一次)，减少了一次赋值操作。

*/


#include <iostream>

/*
#include <iostream>
class Foo {
public: 
  Foo() { printf("Foo constructor. \n");}
};

class Bar : public Foo {
public:
Bar() { printf("Bar constructor. \n");}

};

int main(int argc, char* argv[]) {
//会调用 Foo & Bar的默认构造函数
Bar bar = Bar();


return 0;
}
*/



/*
class Foo{
public:
  Foo(int x) {
    std::cout << "Foo constructor. " << std::endl;
  }
};

class Bar : public Foo {
public:
  Bar():Foo(10) {
    std::cout << "Bar constructor. " << std::endl;
  }
};


int main() {
  //会调用 Foo的自定义构造函数  & Bar的默认构造函数
  Bar bar;
}

*/


//使用初始化列表来初始化字段，除了选择调用父类的哪个构造函数之外，初始化列表还允许指定为类字段的对象调用哪个构造函数。

#include <string>

/**
class Qux{
public:
  Qux(): _foo("initialize foo.");
  
private:
  std::string _foo;

};

class Baz {
public:
  Baz(): _foo(initialize foo first), _bar("then bar") {}
  
private:
  std::string _foo;
  std::string _bar;  
};

**/


//初始化列表和常量字段
//使用初始化列表来初始化字段并不总是必要的，但是对于const字段来说是必须的，如果你有一个const字段，那么它只能被初始化一次，所以它必须在初始化列表中被初始化。

/*
class const_field{
public:
  const_field(): _constant(1) {
    std::cout << "_constant: " << _constant << std::endl;
  }
  // this is an error: const_field() { _constant = 1;}
private:
  const int _constant;  
};


int main() {
  const_field aa;
}
*/


/**
还有什么时候需要使用初始化列表：
无默认构造函数
如果您有一个没有默认构造函数的字段（或没有默认构造函数的父类），则必须指定要使用哪个构造函数
**/



//总结：初始化列表可以指定构造函数  & 对常量属性赋值 & 减少一次赋值操作。


//对于出现单参数的构造函数需要注意: c++会默认将参数对应的类型转换为该类类型，有时候这种隐式的转换是我们不想要的，需要使用explicit 关键字来限制这种转换。


/**
构造顺序：按照定义，不按照初始化

虚拟基类的构造函数（如果有多个虚拟基类，按照它们被继承的顺序构造，而不是它们在成员初始化列表中的顺序）；
非虚拟基类的构造函函（如果有多个非虚拟基类，按照它们被继承的顺序构造，而不是它们在成员初始化列表中的顺序）；
成员对象的构造函数（如果有多个成员类对象，按照它们声明的顺序调用，而不是它们在成员初始化列表中的顺序）；
本类构造函数。构造的过程是递归的。
**/



//拷贝构造函数
/**
1、拷贝构造函数实际上就是构造函数的重载，具有一般构造函数的所有特性，用此类已有的对象创建一个新的对象，一般在函数中会将已存在的对象的数据成员的值复制一份到新创建的对象中。  用类的一个已知的对象去初始化该类的另一个对象，会自动调用对象的拷贝构造函数。

2、返回值是类对象的引用，通过返回引用值可以实现连续构造，即类似 A(B(C))

3、浅拷贝和深拷贝。编译器创建的默认拷贝构造函数只会执行"浅拷贝"，也就是通过赋值完成，如果该类的数据成员中有指针成员，也只是地址拷贝，会使新的对象与拷贝对象的该指针成员指向的地址相同， delete该指针时则会导致两次重复delete而出错。 如果指针成员是new出来的就是"深拷贝"


**/

//析构函数（destructor）

/**
1、析构函数作用是做一些清理工作，delete一个对象或对象生命周期结束时，会自动调用对象的析构函数。
2、析构顺序： 和构造函数顺序相反，析构的过程也是递归的。
**/


//重载赋值运算符函数（Copy Assignment operator）
/**
1、它是两个已有对象，一个给另一个赋值的过程。 当两个对象之间进行赋值的时候，会自动调用重载赋值运算符函数，它不同于拷贝构造函数，拷贝构造函数是用已有的对象给新生的对象赋初值的过程。
2、赋值运算符重载函数参数中const和&没有强制要求，返回值是类对象的引用。 通过返回引用之可以实现连续赋值，类似： a=b=c这样，返回值类型也不是强制的，可以返回void. 这时就不能连续赋值。
3、赋值运算符重载函数智能定义为类的成员函数，不能是静态成员函数也不能是友元函数。 赋值运算符重载函数不能被继承，要避免自赋值。
4、

**/

//重载取址运算符(const)函数

/**
  1、重载取址运算符函数没有参数
  2、如果没有显示定义，编译器会自动生成默认的重载取址运算符函数
**/


//移动构造函数 & 重载移动赋值操作符函数

/**
1、C++11 新增 move语义： 源对象资源的控制权全部交给目标对象，可以将原对象移动到新对象，用于a初始化b后，就将a析构的情况。
2、移动构造函数的参数和拷贝构造函数不同，拷贝构造函数的参数是一个左值引用，但是移动构造函数的初值是一个右值引用。
3、临时对象即将消亡，并且它里边的资源需要被再利用，这个时候就可以使用移动构造，移动构造可以减少不必要的复制，带来性能上的提升。
**/

#include <cstring>


class MyClass{
public:
  MyClass(const char* str = nullptr); //默认带参构造函数
  ~MyClass(void); //默认析构函数
  MyClass(const MyClass&); //默认拷贝构造函数
  MyClass & operator =(const MyClass& ); //默认重载赋值运算符函数
  MyClass * operator &(); //默认重载取址运算符函数
  MyClass const * operator &() const; //默认重载取址运算符const函数
  MyClass(MyClass &&); //默认移动构造函数
  MyClass & operator = (MyClass &&); //默认重载移动赋值操作符函数 
  
  private:
    char * pData_ = nullptr;
};


//Note:如果自己定义了一个构造函数(无论是否有参数),编译器就不会再自动生成默认构造函数了.
//默认带参数构造函数
MyClass::MyClass(const char* str) {
  if (!str) {
    pData_ = nullptr;
  } else {
    pData_ = new char[strlen(str) + 1];
    strcpy(pData_, str);
  }
  std::cout << "默认带参数构造函数: " << "this addr: " << this << std::endl;
}

//默认析构函数
MyClass::~MyClass(void) {
  if(pData_) {
    delete[] pData_;
    pData_ = nullptr;
  }
  std::cout << "默认析构函数: " << "this addr: " << this << std::endl;
}

//默认拷贝构造函数
MyClass::MyClass(const MyClass& m) {
  if(!pData_) {
    pData_ = nullptr;
  } else {
    pData_ = new char[strlen(m.pData_) + 1];
    strcpy(pData_, m.pData_);
  }
  std::cout << "默认拷贝构造函数: " << " this addr: " << this << std::endl;
}

//默认重载赋值运算符函数
MyClass &MyClass::operator =(const MyClass&m) {
  if(this == &m) {
    return *this;
  }
  delete [] this->pData_;
  if(!m.pData_) {
    this->pData_ = nullptr;
  } else {
    this->pData_ = new char[strlen(m.pData_) + 1];
    strcpy(this->pData_, m.pData_);
  }
  std::cout << "默认重载赋值运算符函数: " << "this addr: " << this << std::endl;
  return *this;
}

//默认重载取址运算符函数
MyClass * MyClass::operator &() {
  std::cout << "默认重载取址运算符函数: " << "this addr: " << this << std::endl;
  return this;
}

//默认重载取址运算符const函数
MyClass const* MyClass::operator &() const {
  std::cout << "默认重载取址运算符const函数: " << "this addr: " << this << std::endl;
  return this;
}

//默认移动构造函数
MyClass::MyClass(MyClass && m):pData_(std::move(m.pData_)) {
  std::cout << "默认移动构造函数: " << std::endl;
  m.pData_ = nullptr;
}

//默认重载移动赋值操作符函数
MyClass & MyClass::operator =(MyClass && m) {
  if( this == &m) {
    return *this;
  }
  pData_ = nullptr;
  pData_ = std::move(m.pData_);
  m.pData_ = nullptr;
  std::cout << "默认重载移动赋值操作符函数: " << "this addr: " << this << std::endl;
  return *this;
}


void funcA(MyClass a) {
  std::cout << "调用funcA函数" << "param addr: " << &a << std::endl;
}

void test1(void) {
  std::cout << "===============test1==============" << std::endl;
  MyClass myclass1; //等价于 MyClass myclass1 = MyClass(); 调用默认构造函数
  /**
   1、MyClass()为右值，需要右值引用
   2、先调用默认带参构造函数，然后调用默认重载取址运算符函数
   3、最后调用默认重载移动赋值操作符函数
  */
  myclass1 = MyClass();
  std::cout << "===============test1==============" << std::endl;
  //析构两次 1: myclass1 = MyClass()中的MyClass()  2: MyClass myclass1
}


void test2() {
  std::cout << "===============test2==============" << std::endl;
  
  MyClass myclass1; //等价于MyClass myclass1 = MyClass(); //调用默认带参构造函数

  MyClass myclass2(myclass1); //调用默认拷贝构造函数

  /**
   *1、myclass2为左值，所以此操作为赋值操作，会调用默认重载取址运算符const函数，
   *2、然后调用默认重载赋值运算符函数
  */
  myclass2 = myclass1;

  
  /**
   *1、参数传值会导致赋值操作，会调用默认拷贝构造函数
   *2、然后函数funcA调用默认重载取址运算符函数取得参数
   */
  funcA(myclass1);

  /**
   *1、funcA函数的参数为右值，会调用默认移动构造函数
   *2、然后funcA函数会调用默认重载取址运算符函数取得参数
   *Note:在移动构造函数中对于基本类型所谓移动只是把其值拷贝,
   *对于如string这类类成员来说才会真正的所谓资源移动
   */
  funcA(std::move(myclass1));
  
  std::cout << "===============test2==============" << std::endl;
}




void test3() {
  std::cout << "===============test3==============" << std::endl;
  /**
   *1、调用默认带参构造函数，生成该类对象
   *2、然后funcA函数调用默认重载取值运算符函数取得参数
   */
  funcA(MyClass());
  std::cout << "===============test3==============" << std::endl;
  //Note:析构一次: funcA(MyClass())中的MyClass()形成的对象,是在funcA函数结束调用的时候，调用默认析构函数  
}

void test() {
  //test1();
  //test2();
  test3();
}


int main(int argc, char* argv[]) {
   
  test(); 

  return 0;
}

















