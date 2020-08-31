#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, dp[50001];
int main() {//Four Squares
    cin >> N;
    memset(dp, 50001, sizeof(dp));
    for (int i = 1; i < N; i++) {
        if (i * i > N)
            break;
        dp[i * i] = 1;
    }
    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (j * j > i)
                break;
            dp[i] = min(dp[i], 1 + dp[i - j * j]);
        }
    }
    cout << dp[N] << '\n';
    return 0;
}