#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, INF = 5000001;
long long int dist[501];
vector<pair<int, int>> e[501];
int main() {
    FASTIO;
    cin >> N >> M;
    int a, b, c;
    for (int i = 1; i <= N; i++) {
        dist[i] = INF;
    }
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        e[a].push_back(make_pair(b, c));
    }
    dist[1] = 0;
    bool flag = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k < e[j].size(); k++) {
                if (dist[j] != INF && dist[e[j][k].first] > dist[j] + e[j][k].second) {
                    dist[e[j][k].first] = dist[j] + e[j][k].second;
                    if (i == N)
                        flag = 1;
                }
            }
        }
    }
    if (flag)
        cout << -1;
    else {
        for (int i = 2; i <= N; i++) {
            if (dist[i] == INF)
                cout << -1 << "\n";
            else
                cout << dist[i] << "\n";
        }
    }
    return 0;
}