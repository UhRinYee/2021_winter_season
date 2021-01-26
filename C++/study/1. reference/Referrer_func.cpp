#include <iostream>

// int& function(){      //이 함수의 리턴타입은 int& 이다.
//   int a = 2;
//   return a;
// }

// int main(){
//   int b = function();
//   b = 3;

//   return 0;
// }

/*
이 코드는 사실

int & ref = a;

//a가 사라짐
int b = ref;

가 된것인데. 이러한 경우를 *댕글링 레퍼런스라고 한다.
  
  *약하게 결합된.
*/

int& function(int &a){
  a = 5;

  return a;
}

int main(){
  int b = 2;
  int c = function(b);

  return 0;
}

// 위의 경우 function(b) 를 실행한 시점에서 a 는 main 의 b 를 참조하고 있게 됩니다.
// 따라서 function 이 리턴한 참조자는 아직 살아있는 변수인 b 를 계속 참조 합니다.

//사실상
/*
  int& a = b;
  int c = a;
*/
//가 되는것이다.

// 장점 : 전체 하나씩 복사할것을 포인터 하나로 복사하여 효율적
//      -> 파일 하나씩 옮기는것보다 하나의 파일에 담아 옮기는것이 효율적.

// 참조자가 아닌 값을 리턴하는 함수를 참조자로 받기

/*
int function() {
  int a = 5;
  return a;
}

int main() {
  int& c = function();
  return 0;
}
*/
// 위와 같은경우 당연히 에러 발생. c가 충분히 바뀔 수 있는 상황이기 때문
// 하지만 const를 사용하여 상수로 만들어버린다면 선언 가능.

/*
int function() {
  int a = 5;
  return a;
}

int main() {
  const int& c = function();
  std::cout << "c : " << c << std::endl;
  return 0;
}
*/