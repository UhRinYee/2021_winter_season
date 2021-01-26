#include <iostream>

class Animal{
  private:                                      // private - 접근지시자로 객체 안에서만 접근 가능
    int food;       //
    int weight;     // 체중

  public:                                       // public - 접근지시자로 객체 안,밖에서 모두 접근 가능
    void set_animal(int _food, int _weight){
      food = _food;
      weight = _weight;
    }

    void increase_food(int inc){
      food += inc;
      weight += (inc / 3);
    }
    
    void view_stat(){
      std::cout << "이 동물의 food   : " << food << std::endl;
      std::cout << "이 동물의 weight : " << weight << std::endl;
    }
};      // 세미콜론 꼭

int main(){
  Animal animal;
  animal.set_animal(100, 50);
  animal.increase_food(30);

  animal.view_stat();
  return 0;
}