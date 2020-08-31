#include <iostream>
#include <vector>
using namespace std;
int T, N, M, W, INF = 987654321;
int dist[501];
bool visited[501] = { 0 };
int main() {//웜홀
    //컴포넌트 별로 체크하거나(구현못함) //INF 신경쓰지말고 사이클 있는지만 체크하거나
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M >> W;
        vector<pair<int, int>> edge[501];
        for (int i = 2; i <= N; i++) {
            dist[i] = INF;
        }
        dist[1] = 0;
        visited[1] = 1;
        int S, E, T;
        for (int i = 0; i < M; i++) {
            cin >> S >> E >> T;
            edge[S].push_back(make_pair(E, T));
            edge[E].push_back(make_pair(S, T));
        }
        for (int i = 0; i < W; i++) {
            cin >> S >> E >> T;
            edge[S].push_back(make_pair(E, -T));
        }
        bool MINUS = 0;
        for (int i = 1; i <= N; i++) {
            for (int v = 1; v <= N; v++) {
                for (int w = 0; w < edge[v].size(); w++) {
                    int dest = edge[v][w].first;
                    int d = dist[v] + edge[v][w].second;
                    if (d < dist[dest]) {
                        dist[dest] = d;
                        visited[dest] = 1;
                        if (i == N)
                            MINUS = 1;
                    }
                }
            }
        }
        if (MINUS)
            cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
    return 0;
}