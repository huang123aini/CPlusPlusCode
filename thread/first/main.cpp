#include <iostream>
#include <thread>

// 使用std::thread 我们需要创建一个新的线程对象并向其传递一个可调用对象
// 可调用对象有三种定义方式

/**
 *第一种方式：使用函数对象作为线程对象中的可调用对象
 *函数对象：我们需要一个类，并在该类中重载运算符()
 *
 */

class FunctionObject {
 public:
  // overload () operator
  void operator()(int params) {
    printf("this is a function object for thread \n");
    for (int i = 0; i < params; i++) {
      printf("cur: %d \n", i);
    }
  }
};

/**
 * 第二种通过函数指针
 */
void FunctionPointer(int params) {
  printf("this is a function pointer for thread \n");
  for (int i = 0; i < params; i++) {
    printf("cur: %d \n", i);
  }
}

int main(int argc, char* argv[]) {
  // 函数对象
  FunctionObject funcObj;
  int n = 5;
  std::thread threadByFunctionObject(funcObj, n);
  threadByFunctionObject.join();

  // 函数指针
  std::thread threadByFunctionPointer(FunctionPointer, n);
  threadByFunctionPointer.join();

  // Lambda表达式
  auto lambdaF = [](int params) {
    printf("this is a lambda function for thread \n");
    for (int i = 0; i < params; i++) {
      printf("cur: %d \n", i);
    }
  };
  std::thread threadByLambda(lambdaF, n);
  threadByLambda.join();
  return 0;
}