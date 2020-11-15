#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i<b; i++)
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int t, N, M, T, s, g, h, INF =987654321;
int dist[2001], arr[100];
tuple<int, int, int> compare[100];
vector<pair<int, int>> e[2001];
priority_queue<pair<int, int>> pq;
void dijkstra(int start) {
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    dist[start] = 0;
    pq.push(make_pair(0, start));
    while (!pq.empty()) {
        int xc = -pq.top().first;
        int x = pq.top().second;
        pq.pop();
        if (dist[x] < xc) continue;
        for (int i = 0; i < e[x].size(); i++) {
            int n = e[x][i].first;
            int nc = xc + e[x][i].second;
            if (dist[n] > nc) {
                dist[n] = nc;
                pq.push(make_pair(-nc, n));
            }
        }
    }
}
int main() {
    FASTIO;
    cin >> t;
    FOR(tc, 0, t) {
        cin >> N >> M >> T;
        FOR(i, 1, N + 1) {
            e[i].clear();
        }
        cin >> s >> g >> h;
        int a, b, c;
        int middist;
        FOR(i, 0, M) {
            cin >> a >> b >> c;
            if (a == g && b == h || a == h && b == g)
                middist = c;
            e[a].push_back(make_pair(b, c));
            e[b].push_back(make_pair(a, c));
        }
        FOR(i, 0, T) {
            cin >> arr[i];
        }
        dijkstra(s);
        int tog = dist[g], toh = dist[h];
        FOR(i, 0, T) {
            get<0>(compare[i]) = dist[arr[i]];
        }
        dijkstra(g);//g-t 1 s-h+h-g+g-t
        FOR(i, 0, T) {
            get<1>(compare[i]) = dist[arr[i]];
        }
        dijkstra(h);
        FOR(i, 0, T) {
            get<2>(compare[i]) = dist[arr[i]];
        }
        vector<int> result;
        FOR(i, 0, T) {
            if (get<0>(compare[i]) == min(tog + get<2>(compare[i]), toh + get<1>(compare[i])) + middist)
                result.push_back(arr[i]);
        }
        sort(result.begin(), result.end());
        FOR(i, 0, result.size()) {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}