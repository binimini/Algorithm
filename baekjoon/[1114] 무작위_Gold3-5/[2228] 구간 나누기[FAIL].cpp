#include <bits/stdc++.h>
using namespace std;
int N,M,dp[51][101][2],arr[101], INF = -987654321;
int solution(int cnt, int x, int s) {
    if (cnt > M)
        return INF;
    if (x > N) {
        if (cnt == M)
            return 0;
        else
            return INF;
    }
    if (dp[cnt][x][s] != INF)
        return dp[cnt][x][s];

    int& r = dp[cnt][x][s];
    r = INF + 4000000;
    if (s) {
        return r = max(solution(cnt, x + 1, 0), solution(cnt, x + 1, 1) + arr[x]);
    }
    else {
        return r = max(solution(cnt, x + 1, 0), solution(cnt + 1, x + 1, 1) + arr[x]);
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int j = 0; j <= 50; j++) {
        for (int k = 0; k <= 100; k++) {
            for (int i = 0; i < 2; i++) {
                dp[j][k][i] = INF;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    
    cout<<solution(0, 1, 0);//구간개수 현재arr 이전상태
    return 0;
}