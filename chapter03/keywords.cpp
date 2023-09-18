#include <iostream>


//new & delete
// int main(int argc,char* argv[]) {
//     //malloc & free
//     int *mallocPointer = (int*)malloc(5);
//     free(mallocPointer);
  
//     //new & delete
//     int *newPointer = new int(2);
//     delete newPointer;   
// }



//this this指针 == 创建的对象地址 并且 隐式声明为ClassName* const this;
class Base {
    public:
      void Print() { 
        std::cout << "this pointer: " << this << std::endl; 
      }
};

// int main(int argc, char* argv[]) {
//   Base base;
//   base.Print();
//   std::cout << "base object addr: " << &base << std::endl;

// }


//const & constexpr
#include <array>
// constexpr int foo(int i) {
//     return i + 5;
// }
// int main(int argc, char* argv[]) {
//   int i = 10;
//   std::array<int,foo(5)> arr; //OK
//   std::cout << "constexpr foo function is compare success." << std::endl;
  
//   foo(i); //普通调用 OK
//   std::array<int, foo(i)> arr1; //Error
// }



//delete 禁用函数: 编译器禁止使用已删除的函数
class A{
    public: 
      A() {
         std::cout << "默认构造函数" << std::endl;
      }
};

class B{
    public:
     B() {
        std::cout << "默认构造函数" << std::endl;
     }
     B(const B& other) = delete; //禁用默认拷贝构造函数
     B& operator = (const B& other) = delete; //禁用重载赋值运算符
};

/**
int main(int argc, char* argv[]) {
    A a1;
    A a2(a1); //复制构造函数未被禁用
    std::cout << "compare A success." << std::endl;

    B b1;
    B b2(b1); //编译错误:默认拷贝构造函数被禁用
    B b3;
    b3 = b1; //编译错误:默认重载赋值运算符被禁用
    return 0;
}
**/