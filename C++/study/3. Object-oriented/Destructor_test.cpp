// 소멸자 호출 확인하기
#include <string.h>
#include <iostream>

class Test {
  char c;

 public:
  Test(char _c) {
    c = _c;
    std::cout << "생성자 호출 " << c << std::endl;
  }
  ~Test() { std::cout << "소멸자 호출 " << c << std::endl; }
};

void simple_function() { Test b('b'); }     // 여기서 B가 선언되었으니 이 함수가 끝난다면 B가 소멸된다.

int main() {
  Test a('a');
  simple_function();
}