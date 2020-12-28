#include <bits/stdc++.h>
using namespace std;
long long int dp[117];
int N;
long long int solution(int n) {
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = solution(n - 1) + solution(n - 3);
}
int main() {
    for (int i = 1; i <= 116; i++) {
        dp[i] = -1;
    }
    dp[1] = 1, dp[2] = 1, dp[3] = 1;
    cin >> N;
    cout <<solution(N);
    return 0;
}