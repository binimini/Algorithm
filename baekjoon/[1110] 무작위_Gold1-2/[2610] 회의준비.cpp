#include <bits/stdc++.h>
using namespace std;
int N, M, INF = 1000;
int dist[101], p[101], m[101];
vector<int> e[101];
pair<int, int> result[101];
priority_queue<pair<int, int>> pq;
int find_p(int x) {
    if (p[x] == x)
        return x;
    else
        return p[x] = find_p(p[x]);
}
void union_p(int x, int y) {
    x = find_p(x);
    y = find_p(y);
    if (x < y)
        p[y] = x;
    else
        p[x] = y;
}
void dijkstra(int n) {
    for (int i = 1; i <= N; i++)
        dist[i] = INF;
    dist[n] = 0;
    pq.push(make_pair(0, n));
    while (!pq.empty()) {
        int xc = -pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if (dist[x] < xc) continue;
        for (int i = 0; i < e[x].size(); i++) {
            int n = e[x][i];
            int nc = xc + 1;
            if (dist[n] > nc) {
                dist[n] = nc;
                pq.push(make_pair(-nc, n));
            }
        }
    }
    
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        p[i] = i;
        result[i].first = INF;
    }
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
        union_p(a, b);
    }
    for (int i = 1; i <= N; i++) {
        dijkstra(i);
        int mm = -1;
        for (int j = 1; j <= N; j++) {
            if (dist[j] != INF)
                mm = max(mm, dist[j]);
        }
        m[i] = mm;
    }
    for (int i = 1; i <= N; i++) {
        int pa = find_p(i);
        if (result[pa].first > m[i]) {
            result[pa].first = m[i];
            result[pa].second = i;
        }
    }
    vector<int> r;
    for (int i = 1; i <= N; i++) {
        if (result[i].first != INF)
            r.push_back(result[i].second);
    }
    sort(r.begin(), r.end(), greater<int>());
    cout << r.size() << "\n";
    while(!r.empty()){
        cout << r.back() << "\n";
        r.pop_back();
    }
    return 0;
}