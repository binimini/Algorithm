#include <bits/stdc++.h>
using namespace std;
int N, M, T, lev[100001], dp[100001], dist[100001], INF = 2100000000;
vector<pair<int, int>> tip[100001];
priority_queue<pair<int, int>> pq;
void dijkstra(int node) {
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    dist[node] = 0;
    pq.push(make_pair(0, node));
    int cnt = 1, max_lev = 0;
    while (!pq.empty()) {
        int xc = -pq.top().first;
        int x = -pq.top().second;
        max_lev = max(max_lev, lev[x]);
        if (dp[cnt] < max_lev) break;
        else 
            dp[cnt] = min(max_lev, dp[cnt]);
        if (cnt == M)
            break;
        cnt++;
        for (int i = 0; i < tip[x].size(); i++) {
            lev[tip[x][i].first] -= tip[x][i].second;//관련 노드 비용 감소시키기..
        }
        pq.pop();
        if (dist[x] < xc) continue;
        for (int i = 1; i <= N; i++) {
            if (i == x) continue;
            if (dist[i] > xc + lev[i]) {
                dist[i] = xc + lev[i];
                pq.push(make_pair(-dist[i], i));
            }
        }
    }
    while (!pq.empty())
        pq.pop();
}
int main() {//N = 10^5 1 second O(N*N)->O(NlogN) or O(N)??? 
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> lev[i];
    }
    for (int i = 1; i <= M; i++) {
        dp[i] = INF;
    }
    cin >> T;
    int a, b, c;
    for (int i = 0; i < T; i++) {
        cin >> a >> b >> c;
        lev[b] += c;
        tip[a].push_back(make_pair(b, c));
    }
    for (int i = 1; i <= N; i++) {
        dijkstra(i);//already N*ElogV
    }
    cout << dp[M];
    return 0;
}