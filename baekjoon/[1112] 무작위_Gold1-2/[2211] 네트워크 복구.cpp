#include <bits/stdc++.h>
using namespace std;
int N, M, INF = 10001;
vector<pair<int,int>> e[1001];
pair<int, int> dist[1001];
priority_queue<pair<int, int>> pq;
bool restore[1001][1001] = { 0 };
void dijkstra() {
    for (int i = 1; i <= N; i++) {
        dist[i].first = INF;
    }
    dist[1].first = 0, dist[1].second = { -1 };
    pq.push(make_pair(0, 1));
    while (!pq.empty()) {
        int xc = -pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if (xc > dist[x].first) continue;
        for (int i = 0; i < e[x].size(); i++) {
            int n = e[x][i].first;
            int nc = xc + e[x][i].second;
            if (nc < dist[n].first) {
                dist[n].first = nc;
                dist[n].second = x;
                pq.push(make_pair(-nc, n));
            }
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        e[a].push_back(make_pair(b, c));
        e[b].push_back(make_pair(a, c));
    }
    dijkstra();
    cout << N - 1 << "\n";
    for (int i = 2; i <= N; i++) {
        cout << dist[i].second <<" " << i << "\n";
    }
    return 0;
}