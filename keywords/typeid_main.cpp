#include <iostream>

void TestType() {
	std::cout <<"typeid(int): " << typeid(int).name() << std::endl;
	int a;
	std::cout <<"typeid(a): " << typeid(a).name() << std::endl;

	if(typeid(int) == typeid(a)){
	  std::cout << "int" << std::endl;
	}
}


class Base {
public:
	virtual void Func() {
		std::cout << "Base Func" << std::endl;
	}
};


class A : public Base {
	virtual void Func() {
		std::cout << "A Func " << std::endl;
	}
};

class B : public Base {
	virtual void Func() {
		std::cout << "B Func" << std::endl;
	}
};

void TestClass() {
	Base *ptr = new A();
	std::cout << "typeid(ptr): " << typeid(ptr).name() << " typeid(*ptr): " << typeid(*ptr).name() << std::endl;
	Base *ptr1 = new A();
	Base *ptr2 = new B();
	Base *ptr3 = new A();
	std::cout << "=========================" << std::endl;
	if(typeid(ptr1) != typeid(ptr2)) {
		std::cout << "typeid(ptr)表示当前ptr的类型" << std::endl;
	}
	if(typeid(*ptr1) == typeid(*ptr3)) {
		std::cout << "typeid(*ptr)表示当前指针指向的类型" << std::endl;
	}

}

int main(int argc, char const *argv[])
{
	std::cout << "typeid 基础类型 " << std::endl;
	TestType();
	std::cout << "==============" << std::endl;
	std::cout << "typeid class  " << std::endl;
	TestClass();
	std::cout << "==============" << std::endl;
	return 0;
}