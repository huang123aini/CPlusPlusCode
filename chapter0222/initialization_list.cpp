
//C++ std::initializer_list

#include <iostream>
#include <string>

void InitBasicType() {
  int i { 18 };
  double d { 3.14 };
  char c { 'A' };
  bool b { true };
  std::string s { "hello,world." };

  std::cout << "i: " << i << " d: " << d << 
  " c: " << c << " b: " << b << " s: " << s << std::endl;
}

//{}初始化可以防止缩小转换范围
void InitBasicType2()
{
    int i = 3.14; //允许传统的缩小转换,会有数据丢失的警告

    int j { 3.14 }; //🛑❌

}

int main(int argc, char* argv[]) {
    //InitBasicType();
    //InitBasicType2();
}