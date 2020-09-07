#include <bits/stdc++.h>
using namespace std;
int N, d = 1000000000;
int dp[101][10][1 << 10];
int find_dp(int n, int num, int status) {
    if (status >= (1 << 10))
        return 0;
    if (num > 9 || num < 0)
        return 0;
    if (n > N)
        return 0;

    int& x = dp[n][num][status];
    if (x != -1) {
        return x;
    }
    if (n == N && status == (1 << 10) - 1) {
        return 1;
    }
    x = 0;
    if (n == 0 && num == 0) {
        for (int i = 1; i <= 9; i++) {
            x = (x + find_dp(1, i, status | 1 << i)) % d;
        }
        return x;
    }

    else {
        x = (x + find_dp(n + 1, num + 1, status | 1 << (num + 1))) % d;
        x = (x + find_dp(n + 1, num - 1, status | 1 << (num - 1))) % d;
        return x;
    }
}
int main(){
    cin >> N;
    int sum = 0;
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < 1 << 10; k++) {
                dp[i][j][k] = -1;
            }
        }
    }
    cout <<find_dp(0, 0, 0)<<"\n";
    return 0;
}