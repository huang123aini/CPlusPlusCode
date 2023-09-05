#include <iostream>
#include <memory>

struct B;
struct A
{
  ~A() { std::cout << "dtor ~A \n"; }
  std::shared_ptr<B> b; //A拥有B共享指针
};

struct  B
{
  ~B() { std::cout << "dtor ~B \n"; }
  
  std::weak_ptr<A> a; //B拥有A共享指针	
};


struct C
{
  ~C() { std::cout << "dtor ~C \n"; }
};


void CircularReferenceFunc() {
  std::shared_ptr<A> ptrA = std::make_shared<A>();
  std::shared_ptr<B> ptrB = std::make_shared<B>();
  ptrA->b = ptrB;
  ptrB->a = ptrA;
}

int main(int argc, char const *argv[]) {	
  CircularReferenceFunc();
  printf("now CircularReferenceFunc is Done. \n");
  return 0;
}
