#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, R = 0, cnt = 0;
vector<pair<int, int>> edge[1001];
bool visited[1001] = { 0 };
priority_queue<pair<int, int>> pq;
void prim() {
    while (!pq.empty()) {
        int x = pq.top().second;
        int xc = -pq.top().first;
        pq.pop();
        if (visited[x]) continue;
        visited[x] = 1;
        R += xc;
        if (cnt == N)
            return;
        for (int i = 0; i < edge[x].size(); i++) {
            if (visited[edge[x][i].first]) continue;
            pq.push(make_pair(-edge[x][i].second, edge[x][i].first));
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
        edge[b].push_back(make_pair(a, c));
    }
    
    pq.push(make_pair(0, 1));
    prim();
    cout << R;
    return 0;
}