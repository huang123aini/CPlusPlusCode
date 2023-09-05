#include <iostream>
#include <memory>

struct B;
struct C;

struct A
{
  ~A() { std::cout << "dtor ~A \n"; }

	std::shared_ptr<B> b; //A拥有B共享指针
	std::shared_ptr<C> c;
};

struct  B
{
  ~B() { std::cout << "dtor ~B \n"; }
	std::shared_ptr<A> a; //B拥有A共享指针
	std::shared_ptr<C> c;
};


struct C
{
  ~C() { std::cout << "dtor ~C \n"; }
};

void NormalFunc() {
	std::shared_ptr<A> ptrA = std::make_shared<A>();
	std::shared_ptr<B> ptrB = std::make_shared<B>();
	std::shared_ptr<C> ptrC = std::make_shared<C>();
	ptrA->c = ptrC;
	ptrB->c = ptrC;

}

void CircularReferenceFunc() {
	std::shared_ptr<A> ptrA = std::make_shared<A>();
	std::shared_ptr<B> ptrB = std::make_shared<B>();
	ptrA->b = ptrB;
	ptrB->a = ptrA;
}


int main(int argc, char const *argv[]) {
	NormalFunc();
	printf("now NormalFunc is Done. \n");
	
	CircularReferenceFunc();
	printf("now CircularReferenceFunc is Done. \n");
	return 0;
}
