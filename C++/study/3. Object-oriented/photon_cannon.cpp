#include <iostream>
#include <string.h>

class Photon_Cannon{
  int hp, shield;
  int coord_x, coord_y;
  int damage;
  
  public:
    Photon_Cannon(int x, int y);
    Photon_Cannon(const Photon_Cannon& pc);

    void show_status();
};

Photon_Cannon::Photon_Cannon(const Photon_Cannon& pc){
  std::cout << "복사 생성자 호출 !" << std::endl;
  
  hp = pc.hp;
  shield = pc.shield;
  coord_x = pc.coord_x;
  coord_y = pc.coord_y;
  damage = pc.damage;
}

Photon_Cannon::Photon_Cannon(int x, int y){
  std::cout << "생성자 호출 !" << std::endl;
  
  hp = shield = 100;
  coord_x = x;
  coord_y = y;
  damage = 20;
}

void Photon_Cannon::show_status(){
  std::cout << "Photon Cannon " << std::endl;
  std::cout << " Location : (" << coord_x << ", " << coord_y << ")" << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main(){
  Photon_Cannon pc1(3,3);
  Photon_Cannon pc2(pc1);
  Photon_Cannon pc3 = pc2;

  pc1.show_status();
  pc2.show_status();
}

// 44번째줄 43번째 줄과 동일하게 해석된다.
// 다만 생성자를 호출하고 별개로 pc3 = pc2는 다른 문장이다.
// 디폴트 생성자의 한계. 머리로 이해함!