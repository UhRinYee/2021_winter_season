#include <iostream>

using namespace std;

int n = 1260;
int cnt = 0;

// 가장 먼저 줘야할 동전부터 순서대로 둔다.
int coinTypes[4] = {500 , 100, 50, 10};

int main(){
    for(int i = 0; i < 4; i++){             // for문의 조건문은 동전의 원소 수이다.
        int coin = coinTypes[i];            // 지금 줘야할 동전
        cnt += n / coin;                    // 거스름돈의 갯수
        n %= coin;                          // 남은돈
    }
    cout << cnt << endl;
}