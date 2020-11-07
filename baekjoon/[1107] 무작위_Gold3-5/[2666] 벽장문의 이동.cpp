#include <bits/stdc++.h>
using namespace std;
int N,M,A,B,dp[21][21][21];
int arr[21];
int solution(int m,int l, int r) {
    if (m > M)
        return 0;
    if (dp[m][l][r] != -1)
        return dp[m][l][r];
    return dp[m][l][r] = min(solution(m + 1, arr[m], r) + abs(l - arr[m]), solution(m + 1, l, arr[m]) + abs(r - arr[m]));
}
int main() {
    memset(dp, -1, sizeof(dp));
    cin >> N >> A >> B >> M;
    for (int i = 1; i <= M; i++) {
        cin >> arr[i];
    }
    cout << solution(1, A, B);
}