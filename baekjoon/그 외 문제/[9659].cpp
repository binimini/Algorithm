#include <iostream>
using namespace std;
long long int N;//N int 범위 넘어감
int main() {//돌 게임5
    cin >> N;
    //초기 dp 홀수이면 1, 짝수이면 -1
    //홀수 = 홀수(1 or 3) + 짝수(==-1) 상대가 무조건 짐 == 1 (이김)
    //짝수 = 홀수(1 or 3) + 홀수(==1) 상대가 무조건 이김 == -1 (짐)
    if (N % 2 != 0)
        cout << "SK";
    else if (N % 2 == 0)
        cout << "CY";
    return 0;
}