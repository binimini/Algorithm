#include <iostream>
using namespace std;
long long int dp[101][10], sum = 0;
int N;
int main() {
    cin >> N;
    for (int i = 1; i <= 9; i++) {
        dp[1][i] = 1;
    }
    dp[0][1] = 1;
    for (int i = 2; i <= N; i++) {
        dp[i][1] = (dp[i - 1][2] + dp[i - 2][1]) % 1000000000;
        for (int j = 2; j < 9; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % 1000000000;
        }
        dp[i][9] = dp[i - 1][8] % 1000000000;
    }
    for (int i = 1; i <= 9; i++) {
        sum += dp[N][i];
    }
    cout << sum % 1000000000 << '\n';
    return 0;
}