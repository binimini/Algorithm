#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
bool mapp[301][301] = { 0 };
int N, M, dp[301][301] = { 0 };
int main() {
    FASTIO;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> mapp[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {//오른쪽 아래만 갈수있으므로
        for (int j = 1; j <= M; j++) {//왼->오 위->아래로 dp값 갱신
            dp[i][j] = max(dp[i][j], dp[i][j - 1] + (mapp[i][j] == 1));
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + (mapp[i][j] == 1));
        }
    }
    cout << dp[N][M];
    return 0;
}