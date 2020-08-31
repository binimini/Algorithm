#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
priority_queue < pair<int, int>> pq;
int N, M, R, INF = 987654321;
int item[101], dist[101];
vector<pair<int, int>> edge[101];
void dijkstra() {
    while (!pq.empty()) {
        int V = pq.top().second;
        int VC = -pq.top().first;
        pq.pop();
        if (dist[V] < VC) continue;
        for (int i = 0; i < edge[V].size(); i++) {
            int N = edge[V][i].first;
            int NC = edge[V][i].second;
            if (dist[N] > VC + NC) {
                dist[N] = VC + NC;
                pq.push(make_pair(-dist[N], N));
            }
        }
    }
}
int main() {//서강그라운드
    cin >> N >> M >> R;
    for (int i = 1; i <= N; i++) {
        cin >> item[i];
    }
    int a, b, c;
    for (int i = 0; i < R; i++) {
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
        edge[b].push_back(make_pair(a, c));
    }
    int result = 0;
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            dist[j] = INF;
        }
        dist[i] = 0;
        pq.push(make_pair(0, i));
        dijkstra();
        for (int j = 1; j <= N; j++) {
            if (dist[j] <= M)
                cnt += item[j];
        }
        result = max(cnt, result);
    }
    cout << result << '\n';
    return 0;
}