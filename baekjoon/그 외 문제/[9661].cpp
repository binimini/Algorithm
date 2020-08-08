#include <iostream>
using namespace std;
long long int N;
int main() {//돌 게임7
    cin >> N;
    //dp값 1, -1, 1, 1, -1 로 반복, -1인 경우 5k+2, 5k
    if (N % 5 == 0 || N % 5 == 2)
        cout << "CY";
    else cout << "SK";
    return 0;
}