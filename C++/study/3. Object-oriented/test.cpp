#include <iostream>

int main(){
  int len;
  const char* a = "asdf";
  while(*a){
    len++;
  }
  std::cout << len << std::endl;
}