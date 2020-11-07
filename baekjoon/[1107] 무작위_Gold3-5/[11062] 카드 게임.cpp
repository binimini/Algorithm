#include <bits/stdc++.h>
using namespace std;
int T, N, dp[1000][1000], arr[1000], sum[1000][1000] = { 0 };
int solution(int s, int e) {
    if (s > e)
        return 0;
    if (dp[s][e] != -1)
        return dp[s][e];
    return dp[s][e] = sum[s][e]- min(solution(s + 1, e), solution(s, e - 1));
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (j == i)
                    sum[i][j] = arr[i];
                else
                    sum[i][j] = sum[i][j - 1] + arr[j];
            }
        }
        cout <<solution(0, N - 1)<<"\n";
    }
    return 0;
}