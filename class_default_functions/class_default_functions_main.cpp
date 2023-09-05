#include <iostream>

/**
 *在c++中，一个类有八个默认函数
 *
 *1、默认构造函数
 *
 *2、默认拷贝构造函数
 *
 *3、默认析构函数
 *
 *4、默认重载赋值运算符函数
 *
 *5、默认重载取址运算符函数
 *
 *6、默认重载取址运算符函数const函数
 *
 *7、默认移动构造函数（c++11）
 *
 *8、默认重载移动赋值操作符函数（c++11）
 *
 */




class A {
public:
	//默认构造函数
	A() { std::cout << "默认构造函数" <<" this address: " << this << std::endl; }

	//默认拷贝构造函数
	A(const A&) { std::cout << "默认拷贝构造函数" << " this address: " << this << std::endl; }

	//默认析构函数
	~A() { std::cout << "默认析构函数" << " this address: " << this << std::endl; }

	//默认重载赋值运算符函数
	A& operator= (const A& a) { 
        if(this == &a) {
        	return *this;
        }
		std::cout << "默认重载赋值运算符函数" << "this address: " << this << std::endl;
		return *this; 
	}

	//默认重载取址运算符函数
	A* operator& () {
		std::cout << "默认重载取址运算符函数" << "this address: " << this << std::endl; 
        return this;
    }

	//默认重载取址运算符const函数
	A const* operator& () const {
		std::cout << "默认重载取址运算符const函数" <<" this address: " << this << std::endl; 
        return this;
	}

	//默认移动构造函数
	A(A&&) { std::cout << "默认移动构造函数" <<" this address: " << this << std::endl; }

	//默认重载移动赋值操作符
	A& operator= (const A&& a) { 
		if(this == &a) {
			return *this;
		}
		std::cout << "默认移动构造函数" <<" this address: " << this << std::endl; 
		return *this;
	}

};

void funC(A a) {
	std::cout << "调用函数funC" << " param address: " << &a << std::endl;
}


void Test1() {
	std::cout << "Test1 >>>>>>>>>" << std::endl;
	A a; //等价于 A a = A(); //调用默认构造函数
	a = A(); //A()为右值，需要右值引用 .. 先调用默认构造函数，然后调用默认重载取址运算符函数，最后调用默认重载移动赋值操作符函数
	std::cout << "Test1 <<<<<<<<<" << std::endl;
}

void Test2() {
	std::cout << "Test2 >>>>>>>>>>" << std::endl;
	A a;       //等价于 A a = A(); //调用默认构造函数
	A b(a);    //调用默认拷贝构造函数
	b = a;     //b为左值，所以此操作为赋值操作，会调用默认重载取址运算符const函数，然后调用默认重载赋值运算符函数
	funC(a);  //参数传值会导致赋值操作，会调用默认拷贝构造函数，然后funC函数调用默认重载取址运算符函数取得参数
	funC(std::move(a));   // funC函数的参数现为右值，会调用默认移动构造函数，然后funC函数调用默认重载取址运算符函数取得参数
    
    //在移动构造函数中对于基本类型所谓移动只是把其值拷贝，对于如string这类类成员来说才会真正的所谓资源移动

	std::cout << "Test2 <<<<<<<<<<" << std::endl;

}

void Test3() {

	std::cout << "Test3 >>>>>>>>>>>>" << std::endl;
    funC(A()); // 会调用默认带参构造函数，生成该类的对象，然后funA函数调用默认重载取址运算符函数取得参数
    std::cout << "Test3 <<<<<<<<<<<<" << std::endl;
    // 析构一次 1: funC(A())中的A()形成的对象，是在funC函数结束调用的时候，调用默认析构函数

}




int main(int argc, char const *argv[])
{
	std::cout << "===================Test1=================" << std::endl;
	Test1();
	std::cout << "===================Test2=================" << std::endl;
    Test2();
    std::cout << "===================Test3=================" << std::endl;
    Test3();

	return 0;
}

