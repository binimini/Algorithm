#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int N, E, A, B;
int INF = 987654321;
int dist_A[801], dist_B[801];
priority_queue<pair<int, int>> pq;
vector < pair<int, int>> edge[801];
void dijkstra(int V, int* d) {
    d[V] = 0;
    pq.push(make_pair(0, V));
    while (!pq.empty()) {
        int VERCOST = -pq.top().first;
        int VER = pq.top().second;
        pq.pop();
        if (VERCOST > d[VER]) continue;
        for (int i = 0; i < edge[VER].size(); i++) {
            int NEXT = edge[VER][i].first;
            int NEXTCOST = edge[VER][i].second;
            if (NEXTCOST + VERCOST < d[NEXT]) {
                d[NEXT] = NEXTCOST + VERCOST;
                pq.push(make_pair(-d[NEXT], NEXT));
            }
        }
    }
}
int main() {//특정한 최단 경로
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> E;
    int a, b, c;
    for (int i = 1; i <= N; i++) {
        dist_A[i] = INF;
        dist_B[i] = INF;
    }
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
        edge[b].push_back(make_pair(a, c));
    }
    cin >> A >> B;
    dijkstra(A, dist_A);
    dijkstra(B, dist_B);
    bool check = 0;
    int result = -1;
    if (dist_A[1] == INF || dist_A[B] == INF || dist_B[N] == INF)
        check++;
    else result = dist_A[1] + dist_A[B] + dist_B[N];
    if (dist_B[1] == INF || dist_B[A] == INF || dist_A[N] == INF) {
        if (check)
            cout << -1;
        else cout << result;
    }
    else {
        result = min(result, dist_B[1] + dist_B[A] + dist_A[N]);
        cout << result;
    }
    return 0;
}