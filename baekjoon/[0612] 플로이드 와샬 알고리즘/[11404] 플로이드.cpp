#include <iostream>
#include <algorithm>
using namespace std;
int N, M, d[100][100] = { 0 };
int main() {
    cin >> N >> M;
    int x, y, z;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        if (!d[x - 1][y - 1]) d[x - 1][y - 1] = z;
        else d[x - 1][y - 1] = min(d[x - 1][y - 1], z);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (j == k) continue;
                else if (!d[j][i] || !d[i][k]) continue;
                else {
                    if (!d[j][k]) d[j][k] = d[j][i] + d[i][k];
                    else d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
                }
            }
        }

    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}