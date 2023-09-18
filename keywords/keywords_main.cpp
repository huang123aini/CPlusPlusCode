#include <iostream>



/**
 *@brief: 整型常量指针
 * int const*
 *是指向常量整数的指针 这意味着所声明的变量是一个指针，指向常量整数。
 *实际上，这意味着指针指向一个不应更改的值。
 *在这种情况下，const限定符不会影响指针，因此允许指针指向某个其他地址。
 *第一个 const 关键字可以位于数据类型的任一侧，因此int const*相当于const int*
 */

void Test1() {
  const int q = 5;
  int const* p = &q;
 
  //Compilation error 打开下边的代码编译错误
  //*p = 7;
 
  const int q2 = 7;
 
  //Valid
  p = &q2;
     
}


/**
 *@brief 整型指针常量
 *int *const
 *是指向整数的常量指针 这意味着所声明的变量是指向整数的常量指针。
 *实际上，这意味着指针不应指向其他地址。
 *在这种情况下，const 限定符不会影响整数的值，因此允许更改存储在地址中的值。 
 */

void Test2() {
  int q = 5;
  int *const p = &q;
 
  //Valid
  *p = 7;
  const int q2 = 7;
 
  //Compilation error :整型指针常量初始化后不能再赋值
  //p = &q2;

}



/**
 *@brief: 常量整型指针常量
 * const int * const
 *const int* const是指向常量整数的常量指针 这意味着所声明的变量是指向常量整数的常量指针。
 *实际上，这意味着常量指针指向常量值。
 *因此，指针不应指向新地址，也不应更改所指向的值。
 *第一个 const 关键字可以位于数据类型的任一侧，因此const int* const相当于int const* const
 */
void Test3() {
  const int q = 5;
 
  //Valid
  const int* const p = &q;
 
  //Compilation error
  //*p = 7;
     
  const int q2 = 7;
 
  //Compilation error
  //p = &q2;
}

int main(int argc, char const *argv[])
{
  std::cout << "整型常量指针：int const * " << std::endl;	
  Test1();
  std::cout << "=======================" << std::endl;

  std::cout << "整型指针常量： int * const" << std::endl;
  Test2();
  std::cout << "=======================" << std::endl;

  std::cout << "常量整型指针常量： const int * const " << std::endl;
  Test3();
  std::cout << "=======================" << std::endl;


  return 0;
}
