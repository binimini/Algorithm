#include <bits/stdc++.h>
using namespace std;
int V, E, INF = 987654321;
int adj[401][401] = { 0 };
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> V >> E;
    for (int i = 1; i <= V; i++) {
        for (int j = 1; j <= V; j++) {
            adj[i][j] = INF;
        }
    }
    int a, b, c;
    for (int i = 0; i < E; i++) {
        cin >> a >> b >> c;
        adj[a][b] = c;
    }
    for (int k = 1; k <= V; k++) {
        for (int i = 1; i <= V; i++) {
            for (int j = 1; j <= V; j++) {
                if (adj[i][j] > adj[i][k] + adj[k][j])
                    adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
    }
    int result = INF;
    for (int i = 1; i <= V; i++) {
        result = min(result, adj[i][i]);
    }
    if (result == INF)
        cout << -1;
    else
        cout << result;
    return 0;
}