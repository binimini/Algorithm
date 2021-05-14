#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, K;
int path[251][251] = { 0 }, ans[251][251];
int main() {
    FASTIO;
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            path[i][j] = M;
        }
    }
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        if (c) {
            path[a][b] = 0;
            path[b][a] = 0;
        }
        else {
            path[a][b] = 0;
            path[b][a] = 1;
        }
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (path[i][k] + path[k][j] < path[i][j]) {
                    path[i][j] = path[i][k] + path[k][j];
                }
            }
        }
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        cout << path[a][b] << "\n";
    }
    return 0;
}