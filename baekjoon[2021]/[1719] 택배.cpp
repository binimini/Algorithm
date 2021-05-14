#include <bits/stdc++.h>
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int N, M, INF = 987654321;
int d[201][201], ans[201][201] = { 0 };
int main() {
    FASTIO;
    cin >> N >> M;
    int a, b, c;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;
        ans[a][b] = b;
        ans[b][a] = a;
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    ans[i][j] = ans[i][k];
                }
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (ans[i][j] == 0)
                cout << "- ";
            else
                cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}