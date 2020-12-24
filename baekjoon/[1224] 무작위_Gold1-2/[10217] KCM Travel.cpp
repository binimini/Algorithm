#include <bits/stdc++.h>
using namespace std;
int dp[101][10001];
int T, N, M, K, INF = 987654321;
vector<pair<pair<int, int>, int>> edge[101];
//비용, 목적지
void dijkstra() {
    priority_queue<pair<pair<int, int>, int>> pq;
    pq.push(make_pair(make_pair(0, 0), 1));
    while (!pq.empty()) {
        int xd = -pq.top().first.first;//시간
        int xc = -pq.top().first.second;
        int x = pq.top().second;
        if (x == N)
            return;
        pq.pop();
        if (dp[x][xc]!=-1&&dp[x][xc] < xd) continue;
        for (int i = 0; i < edge[x].size(); i++) {
            int n = edge[x][i].first.first;
            int nc = edge[x][i].first.second;
            int nd = edge[x][i].second;//시간
            if (nc + xc <= M && (dp[n][xc + nc] == -1||dp[n][xc+nc]>nd+xd)) {//dp[n][xc+nc]>nd+xd
                dp[n][xc + nc] = nd + xd;
                pq.push(make_pair(make_pair(-dp[n][xc + nc], -(xc + nc)),n));
            }
        }
    }

}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M >> K;
        for (int i = 1; i <= N; i++)
            edge[i].clear();
        int u, v, c, d;
        for (int i = 0; i < K; i++) {
            cin >> u >> v >> c >> d;
            edge[u].push_back(make_pair(make_pair(v, c), d));
        }
        memset(dp, -1, sizeof(dp));
        dp[1][0] = 0;
        dijkstra();
        int result = INF;
        for (int i = 0; i <= M; i++) {
            if (dp[N][i] != -1)
                result = min(dp[N][i], result);
        }
        if (result == INF)
            cout << "Poor KCM\n";
        else
            cout << result << "\n";
    }
    return 0;
}