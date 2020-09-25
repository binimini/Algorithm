#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int S, dp[1001][1001] = { 0 }, INF = 5000;
int find(int n,int clip) {
    if (n > 1000 || n < 1)
        return INF;
    if (n == S)
        return 0;
    if (dp[n][clip] != -1) {//INF로 예외처리시 재귀할때 ref값 초기화된지 알 수 없기에 무한루프
        //ex) 1,1 복사시에도 1,1 이면 -1아니므로 종료되게 해야함
        return dp[n][clip];
    }
    int& ref = dp[n][clip];
    ref = INF;
    ref = min(find(n, n) + 1, ref);
    ref = min(find(n + clip, clip) + 1, ref);
    ref = min(find(n - 1, clip) + 1, ref);


    return ref;
}
int main() {
    cin >> S;
    memset(dp, -1, sizeof(dp));
    cout << find(1,0) << '\n';
    
    return 0;
}