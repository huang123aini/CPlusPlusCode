#include <functional>
#include <iostream>

void PrintNum(int i) {
  std::cout << "store a function pointer: " << i << std::endl;
}

class A {
 public:
  A(int num) : num_(num) {}
  void PrintNum(int n) const {
    std::cout << "store a call to a member function: " << num_ << std::endl;
  }

 private:
  int num_;
};

class B {
 public:
  B(int num) : num_(num) {}

 public:
  int num_;
};

class C {
 public:
  void operator()(int n) const {
    std::cout << "other function object: " << n << std::endl;
  }
};

int main(int argc, char* argv[]) {
  // 1、store a function by function pointer
  std::function<void(int)> func1 = PrintNum;
  func1(1);

  // 2、lambda expressions
  std::function<void()> func2 = []() {
    std::cout << "store a lambda expressions:2" << std::endl;
  };
  func2();

  // 3、bind expressions
  // store the result of a call to std::bind
  std::function<void()> func3 = std::bind(PrintNum, 3);
  func3();

  // 4、pointer to member function
  // store a call to a member function
  std::function<void(const A&, int)> func4 = &A::PrintNum;
  const A a(4);
  func4(a, 4);

  // 5、pointer to data member
  std::function<int(B const&)> func5 = &B::num_;
  const B b(5);
  std::cout << "pointer to data member: " << func5(b) << std::endl;

  // 6、other function objects
  // store a call to a function object
  std::function<void(int)> func6 = C();
  func6(6);

  return 0;
}