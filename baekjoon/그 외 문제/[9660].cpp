#include <iostream>
using namespace std;
long long int N;
int main() {//돌 게임6
    cin >> N;
    //dp값 -1인 경우 : (1num) 2 (4num) 7 (1num) 9 (4num) 14...
    //== 7, 14, 21..(7k) + 2, 9, 16...(7k+2)
    if (N % 7 == 0 || N % 7 == 2)
        cout << "CY";
    else cout << "SK";
    return 0;
}