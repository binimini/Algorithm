#include <iostream>
#include <algorithm>
using namespace std;
int N, W[16][16], dp[16][1 << 16] = { 0 };
int MAX = 21000000, cnt = 210000000;
//시작점 어디든 한바퀴 순회해야하므로 상관없음 따라서 시작점 하나로 고정
int D(int node, int state) {//방문하지 않은 나머지 마을 모두 방문하고 시작점으로 돌아오는 최단거리
    if (state == ((1 << N) - 1)) {
        if (W[node][0] == 0)
            return MAX;//불가능
        return W[node][0];//모두 방문한 상태이므로 돌아가는 거리가 최단거리
    }
    if (dp[node][state] != 0)
        return dp[node][state];
    dp[node][state] = MAX;
    for (int i = 0; i < N; i++) {
        if (W[node][i] == 0) continue;
        if (state & (1 << i)) continue;//방문여부 체크
        int s = state | (1 << i);
        dp[node][state] = min(dp[node][state], D(i, s) + W[node][i]);//DP
    }
    return dp[node][state];
}
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }
    cout << D(0, 1);
    return 0;
}