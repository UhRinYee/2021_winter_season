#include <iostream>

int main() {
  int arr[3] = {1, 2, 3};
  int(&ref)[3] = arr;

  ref[0] = 2;
  ref[1] = 3;
  ref[2] = 1;

  std::cout << arr[0] << arr[1] << arr[2] << std::endl;
  return 0;
}

// 배열의 레퍼런스는 배열 자체를 선언해줘야 한다.
// int& arr[2] = {a, b}; 이리 선언은 안된다.