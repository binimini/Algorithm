#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, ans[201][201] = { 0 }, INF = 987654321;
priority_queue<pair<int, int>> pq;
int dist[201];
vector<pair<int,int>> edge[201];
void dijkstra(int s) {
    pq.push(make_pair(0, s));
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    dist[s] = 0;
    while (!pq.empty()) {
        int xc = -pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if (dist[x] < xc) continue;
        for (int i = 0; i < edge[x].size(); i++) {
            int n = edge[x][i].first;
            int nc = edge[x][i].second;
            if (dist[n] > xc + nc) {
                dist[n] = xc + nc;
                if (s!=x)
                    ans[s][n] = ans[s][x];
                pq.push(make_pair(-dist[n], n));
            }
        }
        
    }
}
int main() {
    FASTIO;
    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b,c));
        edge[b].push_back(make_pair(a,c));
        ans[a][b] = b;
        ans[b][a] = a;

    }
    for (int i = 1; i <= N; i++) {
        dijkstra(i);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (ans[i][j] == 0)
                cout << "- ";
            else
                cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}