#include <bits/stdc++.h>
using namespace std;
int N, M, R = 1;
bool flag = 1;
int mapp[50][50], d[3][2] = { {0,1},{1,0},{1,1} };
int solution() {
    for (int x = min(N, M); x >= 1; x--) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                flag = 1;
                for (int k = 0; k < 3; k++) {
                    int ni = i + d[k][0] * x;
                    int nj = j + d[k][1] * x;
                    if (ni<0 || ni>N - 1 || nj<0 || nj>M - 1) {
                        flag = 0;
                        break;
                    }
                    if (mapp[ni][nj] != mapp[i][j]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    return (x + 1) * (x + 1);
                }
            }
        }
    }
    return 1;
}
int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> N >> M;
    char temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            mapp[i][j] = temp-'0';
        }
    }
    cout << solution();
    return 0;
}