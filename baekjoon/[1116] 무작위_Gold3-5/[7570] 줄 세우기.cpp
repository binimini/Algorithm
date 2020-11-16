#include <bits/stdc++.h>
using namespace std;
int N, dp[1000001] = { 0 };
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int temp, result = 0;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        dp[temp] = dp[temp - 1] + 1;
        result = max(result, dp[temp]);
    }
    cout << N-result;
    return 0;
}