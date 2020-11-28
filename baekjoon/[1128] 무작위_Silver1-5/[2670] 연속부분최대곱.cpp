#include <bits/stdc++.h>
using namespace std;
int N;
double arr[10001],dp[10001];
int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    dp[0] = 1;
    double result = 0;
    for (int i = 1; i <= N; i++) {
        dp[i] = max(dp[i - 1] * arr[i], arr[i]);
        result = max(result, dp[i]);
    }
    cout << fixed << setprecision(3);
    cout << result;
    return 0;
}