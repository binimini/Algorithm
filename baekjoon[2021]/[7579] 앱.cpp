#include <bits/stdc++.h>
using namespace std;
int N, M, dp[101][10001], m[101], c[101], result = 1000000;
int solution(int i, int j) {//top-down
    if (i < 1)
        return 0;
    if (j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];

    int& r = dp[i][j];
    r = 0;
    if (j >= c[i])
        r = max(solution(i - 1, j - c[i]) + m[i], solution(i - 1, j));
    else
        r = solution(i - 1, j);
    return r;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> m[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> c[i];
    }
    
    memset(dp, -1, sizeof(dp));
    solution(0, 0);
    
    for (int i = 0; i <= 10000; i++) {
        if (solution(N, i) >= M) {//재활용 비용 합 i까지만 사용할때의 최대 byte -> bottom-up이면 어떻게 달라질까
            cout << i;
            break;
        }
    }
    return 0;
}