#include <iostream>
using namespace std;
int N, M;
bool adj[101][101] = { 0 };
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a][b] = 1;
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (adj[i][k] && adj[k][j])//i>k k>j i>j
                    adj[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            if (!adj[i][j]&&!adj[j][i]) {// i>j j>i 둘다 검사
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}