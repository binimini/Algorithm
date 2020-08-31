#include <bits/stdc++.h>
using namespace std;
int T, N, M, arr[101][101] = { 0 };
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        char temp;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                cin >> temp;
                if (temp == 'R')
                    arr[i][j] = 1;
                else if (temp == 'D')
                    arr[i][j] = -1;
                else arr[i][j] = 0;
            }
        }
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (arr[i][M - 1] != -1)
                cnt++;
        }
        for (int j = 0; j < M; j++) {
            if (arr[N - 1][j] != 1)
                cnt++;
        }
        cout << cnt - 2 << "\n";
    }
    return 0;
}