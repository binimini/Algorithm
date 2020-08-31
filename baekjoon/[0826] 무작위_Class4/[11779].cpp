#include <iostream>
#include <queue>
#include <vector>
using namespace std;
priority_queue<pair<int, int>> pq;
int N, M, A, B, INF = 987654321;
pair<int, int> dist[1001];
vector<pair<int, int>> edge[1001];
void dijkstra() {
    while (!pq.empty()) {
        int VERCOST = -pq.top().first;
        int VER = pq.top().second;
        pq.pop();
        if (VER == B)
            return;

        if (dist[VER].first < VERCOST) continue;
        
        for (int i = 0; i < edge[VER].size(); i++) {
            int N = edge[VER][i].first;
            int NCOST = edge[VER][i].second;
            if (dist[N].first > NCOST + VERCOST) {
                dist[N].first = NCOST + VERCOST;
                dist[N].second = VER;
                pq.push(make_pair(-dist[N].first, N));
            }
        }
    }
}
int main() {//최소비용 구하기 2
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        dist[i].first = INF;
    }
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
    }
    cin >> A >> B;
    
    pq.push(make_pair(0, A));
    dist[A].first = 0;
    dist[A].second = -1;
    dijkstra();
    
    int preVER = B, cnt = 0;
    vector<int> route;
    while (preVER != -1) {
        route.push_back(preVER);
        cnt++;
        preVER = dist[preVER].second;
    }
    
    cout << dist[B].first << "\n" << cnt << '\n';
    while (!route.empty()) {
        cout << route.back() << " ";
        route.pop_back();
    }
    return 0;
}