#include <iostream>
#include <queue>
using namespace std;
int V, E, K, INF = 987654321;
vector<pair<int, int>> graph[20001];
vector<int> dijkstra(int s, int v) {
    vector<int> dist(v, INF);
    dist[s] = 0;
    priority_queue<pair<int, int>> pq;//cost, vertex // pq 설정 바꿀시 부호 안바꿔도
    pq.push(make_pair(0, s));
    while (!pq.empty()) {
        int cost = -pq.top().first;//현재 비용
        int curV = pq.top().second;//현재 노드
        pq.pop();

        if (dist[curV] < cost) continue;//최소거리보다 현재 비용이 더 크면 패스

        for (int i = 0; i < graph[curV].size(); i++) {
            int neighbor = graph[curV][i].first;//인접 노드
            int neighborDist = cost + graph[curV][i].second;// 인접 노드 거리(현재 노드 통한)

            if (dist[neighbor] > neighborDist) {//더 작으면 업데이트
                dist[neighbor] = neighborDist;
                pq.push(make_pair(-neighborDist, neighbor));//우선순위큐에 집어넣음 
            }
        }
    }
    return dist;
}
int main() {//최단경로
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E >> K;
    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));//노드, 비용
    }
    
    vector<int> result = dijkstra(K,V+1);
    
    for (int i = 1; i <= V; i++) {
        if (result[i] == INF)
            cout << "INF\n";
        else cout << result[i] << '\n';
    }
    return 0;
}