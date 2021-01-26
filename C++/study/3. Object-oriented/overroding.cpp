// 함수의 오버로딩
#include <iostream>

void print(int x){ std::cout << "int : " << x << std::endl; }
void print(char x){ std::cout << "char : " << x << std::endl; }
void print(double x){ std::cout << "double : "<< x << std::endl; }

int main(){
  int a = 1;
  int b = 'a';
  double c = 3.2;

  print(a);
  print(b);
  print(c);

  return 0;
}