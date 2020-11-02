#include <bits/stdc++.h>
using namespace std;
int N, M;
bool adj[501][501] = { 0 };
int main() {
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a][b] = 1;//a<b
    }
    for (int i = 1; i <= N; i++) {
        adj[i][i] = 1;
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (adj[i][k] && adj[k][j])
                    adj[i][j] = 1;
            }
        }
    }
    int cnt = 0;
    bool flag;
    for (int i = 1; i <= N; i++) {
        flag = 1;
        for (int j = 1; j <= N; j++) {
            if (!adj[i][j] && !adj[j][i]) {
                flag = 0;
                break;
            }
        }
        if (flag)
            cnt++;
    }
    cout << cnt << '\n';
    return 0;
}