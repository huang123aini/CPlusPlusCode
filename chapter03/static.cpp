#include <iostream>

void static_variable_in_function() {
  
  /**
   *static变量定义在函数内部
   */	
  static int variable = 0;
  std::cout << " variable: " << variable << 
     " variable address: " << &variable << std::endl;
  variable++; 
}

void CallFunc() {
	//调用 static_variable_in_function 10次
	for (int i = 0; i < 10; ++i)
	{
		static_variable_in_function();
	}
}


class Student {
public:
   /**
    *static数据成员声明在类内部
    */	
   static int age_;

};

int Student::age_ = 18;


void TestClassStaticVariable() {
	std::cout << "直接通过类名调用static成员变量: " << Student::age_ << std::endl;

	Student* student1 = new Student();

	Student* student2 = new Student();

	std::cout << " student1 对象: " << student1->age_ 
	          << " student1 age_ address: " << &(student1->age_) << std::endl;
	std::cout << " student2 对象: " << student2->age_ 
	          <<" student1 age_ address: " << &(student1->age_) << std::endl;

	/**
	 *修改student1 & student2 age_
	 */

	student1->age_++;
	student2->age_ += 2;

	std::cout << " student1 对象 age_ +1: " << student1->age_ 
	          << " student1 age_ address: " << &(student1->age_) << std::endl;

	std::cout << " student2 对象 age_ +=2: " << student2->age_ 
	          <<" student1 age_ address: " << &(student1->age_) << std::endl;           

}

void ExternalFunction() {
	std::cout << "this is a external function" << std::endl;
}

class TestClass {
public:
	static int age_;
	int count_ = 1;
	static void PrintAge() {
		std::cout << "age: " << age_ << std::endl;
	}

	// static void PrintCount() {
	// 	std::cout << "count: " << count_ << std::endl;
	// }

	static void CallExternalFunction() {
      //调用类外部的函数		
      ExternalFunction();
	}
};


class TestStaicInstance {
public:
	TestStaicInstance() { 
      std::cout << "TestStaicInstance 构造" << std::endl;
	}
	~TestStaicInstance() {
      std::cout << "TestStaicInstance 析构" << std::endl;
 	}

};



int main(int argc, char const *argv[])
{   
	//std::cout << " static variable in function " << std::endl;
	//CallFunc();

	//std::cout << " static variable in class " << std::endl;
	//TestClassStaticVariable();

	// std::cout << "call class external function " << std::endl;
	// TestClass::CallExternalFunction();

	{
		TestStaicInstance obj;
	}

	{
		static TestStaicInstance obj;
	}

	std::cout << "主函数结束..." << std::endl;

	return 0;
}
