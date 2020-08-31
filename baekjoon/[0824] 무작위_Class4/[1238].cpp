#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M, X;
int INF =987654321;
priority_queue<pair<int, int>> pq;
vector<pair<int, int>> edge_FX[1001], edge_TX[1001];
int dist_FX[1001], dist_TX[1001];
void dijkstra(vector<pair<int,int>>* e, int* d) {
    pq.push(make_pair(0, X));//cost, vertex
    while (!pq.empty()) {
        int CURCOST = -pq.top().first;
        int CURVER = pq.top().second;
        pq.pop();
        if (CURCOST > d[CURVER]) continue;
        for (int i = 0; i < e[CURVER].size(); i++) {
            int NEXTVER = e[CURVER][i].first;
            int NEXTCOST = e[CURVER][i].second;
            if (d[NEXTVER] > NEXTCOST + CURCOST) {
                d[NEXTVER] = NEXTCOST + CURCOST;
                pq.push(make_pair(-d[NEXTVER], NEXTVER));
            }
        }
    }
}
int main(){//파티
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> X;
    for (int i = 1; i <= N; i++) {
        dist_FX[i] = INF;
        dist_TX[i] = INF;
    }
    dist_FX[X] = 0;
    dist_TX[X] = 0;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        edge_FX[a].push_back(make_pair(b, c));
        edge_TX[b].push_back(make_pair(a, c));
    }
    dijkstra(edge_FX, dist_FX);
    dijkstra(edge_TX, dist_TX);
    int m = -1;
    for (int i = 1; i <= N; i++) {
        m = max(m, dist_FX[i] + dist_TX[i]);
    }
    cout << m << '\n';
    return 0;
}