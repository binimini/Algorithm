#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
#define FOR(i,a,b) for(int i = a; i<b; i++)
int T, N, M, S, D, INF = 500001, CNT = 1;
vector<pair<int,int>> edge[500];
pair<int,vector<int>> dist[500];
int visited[500] = { 0 };
int cant_use[500][500] = { 0 };
priority_queue<pair<int, int>> pq;
queue<int> q;
void dijkstra() {
    while (!pq.empty()) {
        int v = pq.top().second;
        int vc = -pq.top().first;
        pq.pop();
        if (dist[v].first < vc) continue;
        for (int i = 0; i < edge[v].size(); i++) {
            int n = edge[v][i].first;
            int nc = edge[v][i].second;
            if (cant_use[v][n]==CNT)
                nc = INF;
            if (vc + nc <= dist[n].first) {
                if (vc + nc < dist[n].first) {
                    dist[n].second.clear();
                    dist[n].first = vc + nc;
                    pq.push(make_pair(-dist[n].first, n));//같은 거리값으로 들어왔으면 pq에 새로 넣을 필요 X //경로에만 추가

                }
                dist[n].second.push_back(v);

            }
        }
    }
}
int main() {
    FASTIO;
    while (1) {
        CNT++;
        cin >> N >> M;
        if (!N && !M) break;
        FOR(i, 0, N)
            edge[i].clear();
        cin >> S >> D;
        int a, b, c;
        FOR(i, 0, M) {
            cin >> a >> b >> c;
            edge[a].push_back(make_pair(b, c));
        }
        FOR(i,0,N) {
            dist[i].first = INF;
        }
        dist[S].first = 0;
        pq.push(make_pair(0, S));
        dijkstra();
        q.push(D);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            if (visited[x] == CNT) continue;//이미 체크한 x의 사용한 경로 반복체크 없애는 용도
            visited[x] = CNT;
            FOR(i, 0, dist[x].second.size()) {
                cant_use[dist[x].second[i]][x] = CNT;
                if (dist[x].second[i] == S) continue;
                q.push(dist[x].second[i]);
            }
        }
        FOR(i, 0, N) {
            dist[i].first = INF;
        }
        dist[S].first = 0;
        pq.push(make_pair(0, S));
        dijkstra();
        if (dist[D].first >= INF)
            cout << -1 << "\n";
        else
            cout << dist[D].first << "\n";
    }
    return 0;
}