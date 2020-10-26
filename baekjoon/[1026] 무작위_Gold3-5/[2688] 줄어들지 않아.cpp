#include <iostream>
using namespace std;
long long int dp[65][10] = { 0 };
int T, N;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 0; i <= 9; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= 64; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= j; k++) {
                dp[i][j] += dp[i - 1][k];
            }
        }
    }
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        long long int sum = 0;
        for (int i = 0; i <= 9; i++) {
            sum += dp[N][i];
        }
        cout << sum << '\n';
    }
    return 0;
}