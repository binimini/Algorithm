#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, sum[1025][1025] = { 0 };
int main() {
    FASTIO;
    cin >> N >> M;
    int num;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> num;
            sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + num;//(1,1) - (N,N)
        }
    }
    int x1, y1, x2, y2;
    for (int i = 0; i < M; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] <<"\n";
    }
    return 0;
}