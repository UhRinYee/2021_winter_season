#include <iostream>

int main(){
  //int &ref = 4;                       // 이건 ref를 다른 임의의 값으로 바꿀 수 있는 상황이라 에러가 뜨지만
  const int& ref = 4;                   // const를 사용해 값을 바꾸지 못하게 한다면 선언이 가능하다.  
  std::cout << ref << std::endl;
}