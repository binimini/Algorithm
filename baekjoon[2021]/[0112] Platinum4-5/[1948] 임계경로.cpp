#include <bits/stdc++.h>
using namespace std;
int N, M, start_city, end_city;
vector<pair<int, int>> edge[10001], result;
vector<pair<int,int>> reverse_edge[10001];
int dist[10001] = { 0 };
bool visited[10001] = { 0 };
void dfs(int node, int cost) {//다익스트라 최장거리 버전이랑 비슷
    for (int i = 0; i < edge[node].size(); i++) {
        int next = edge[node][i].first;
        int nextcost = edge[node][i].second;
        if (dist[next] < dist[node] + nextcost) {
            dist[next] = dist[node] + nextcost;
            dfs(next, dist[next]);
        }
    }

}
int bfs() {
    int cnt = 0;
    queue<int> q;
    visited[end_city] = 1;
    q.push(end_city);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < reverse_edge[x].size(); i++) {
            int n = reverse_edge[x][i].first;
            int nc = reverse_edge[x][i].second;
            if (dist[n] + nc == dist[x]) {//최대 길 vector에 넣어놓고 tracking하는 방식으로 하면
                //각 다른 두 길에서 같은 노드 방문하는 길 못세거나(node의 visited 체크) 중복으로(체크 안할 시) 세게된다
                //그치만 bfs식으로 최대 비용과 비교하는 식으로 방문하고, 안방문했던 점만 q에 넣으면 중복도 해결된다!!!
                cnt++;
                if (!visited[n]) {
                    visited[n] = 1;
                    q.push(n);
                }
            }
        }
    }
    return cnt;
}
int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
        reverse_edge[b].push_back(make_pair(a, c));
    }
    cin >> start_city >> end_city;
    dfs(start_city, 0);
    cout <<dist[end_city]<<"\n";
    cout << bfs();
    return 0;
}