#include <iostream>
#include <string.h>

class Marine{
  int hp;                                               // 마린 체력
  int coord_x, coord_y;                                 // 마린 위치
  int damage;                                           // 공격력
  bool is_dead;
  char* name;                                           // 마린 이름

  public:
    Marine();                                           // 기본 생성자
    Marine(int x, int y, const char* marine_name);      // 이름까지 지정
    Marine(int x, int y);                               // x,y 좌표에 마린 생성
    ~Marine();

    int attack();                                       // 데미지를 리턴한다.
    void be_attacked(int damage_earn);                  // 받는 데미지
    void move(int x, int y);                            // 새로운 위치


    void show_status();                                 // 상태를 보여준다.
};

Marine::Marine(){
  hp = 50;
  coord_x = coord_y = 0;
  damage = 5;
  is_dead = false;
  name = NULL;
}

Marine::Marine(int x, int y, const char* marine_name){
  name = new char[strlen(marine_name) + 1];
  strcpy(name, marine_name);                        // 2번째 인자를 첫번째 인자로 복사

  coord_x = x;
  coord_y = y;
  hp = 50;
  damage = 5;
  is_dead = false;
}

Marine::Marine(int x, int y){
  coord_x = x;
  coord_y = y;
  hp = 50;
  damage = 5;
  is_dead = false;
}

void Marine::move(int x, int y){
  coord_x = x;
  coord_y = y;
}

int Marine::attack(){ return damage; }

void Marine::be_attacked(int damage_earn){
  hp -= damage_earn;
  if(hp <= 0) is_dead = true;
}

void Marine::show_status(){
  std::cout << " *** Marine : " << name << "***" << std::endl;
  std::cout << " Location : (" << coord_x << ", " << coord_y << ")" << std::endl;
  std::cout << " HP : " << hp << std::endl; 
}

Marine::~Marine(){
  std::cout << name << "의 소멸자 호출 ! " << std::endl;
  if(name != NULL){
    delete[] name;
  }
}

int main(){
  // Marine marine1(2, 3);
  // Marine marine2(3, 5);

  // marine1.show_status();
  // marine2.show_status();

  // std::cout << std::endl << "마린 1이 마린 2를 공격!" << std::endl;
  // marine2.be_attacked(marine1.attack());

  // marine1.show_status();
  // marine2.show_status();
  // 마린1, 마린2 이렇게 붙이면 너무 힘들기때문에 포인터로 구현을 해준다.

  Marine* marines[100];

  marines[0] = new Marine(2, 3, "Marine 2");      // malloc의 경우 동적할당만 해주지만
  marines[1] = new Marine(3, 5, "Marine 1");      // new는 객체를 동적으로 생성하며 생성자도 호출해준다.

  marines[0] -> show_status();
  marines[1] -> show_status();

  std::cout << std::endl << "마린1이 마린2를 공격!" << std::endl;

  marines[0]->be_attacked(marines[1]->attack());

  marines[0] -> show_status();
  marines[1] -> show_status();

  delete marines[0];
  delete marines[1];
}


