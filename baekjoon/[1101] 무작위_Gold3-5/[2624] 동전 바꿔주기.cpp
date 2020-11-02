#include <bits/stdc++.h>
using namespace std;
int T, K, dp[10001][101];
pair<int,int> arr[101];
int solution(int price, int n) {
    if (price < 0)
        return 0;
    if (n >= K) {
        if (price == 0)
            return 1;
        else
            return 0;
    }
    if (dp[price][n] != -1)
        return dp[price][n];
    int& r = dp[price][n];
    r = 0;
    for (int i = 0; i <= arr[n].second; i++) {
        r += solution(price - arr[n].first * i, n + 1);
    }
    return r;

}
int main() {
    memset(dp, -1, sizeof(dp));
    cin >> T;
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> arr[i].first >> arr[i].second;//금액 개수
    }
    cout << solution(T, 0);
    return 0;
}