#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int V, E, cnt = 0, R = 0;
bool visited[10001] = { 0 };
vector<pair<int, int>> edge[10001];
priority_queue<pair<int, int>> pq;
void prim() {
    while (!pq.empty()) {
        int x = pq.top().second;
        int xc = -pq.top().first;
        pq.pop();
        if (visited[x]) continue;
        visited[x] = 1;
        R += xc;
        cnt++;
        if (cnt == V) return;
        for (int i = 0; i < edge[x].size(); i++) {
            if (visited[edge[x][i].first]) continue;
            pq.push(make_pair(-edge[x][i].second, edge[x][i].first));
        }
    }
}
int main() {//최소 스패닝 트리
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> V >> E;
    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
        edge[b].push_back(make_pair(a, c));
    }

    pq.push(make_pair(0, 1));
    prim();
    cout << R << '\n';
    return 0;
}