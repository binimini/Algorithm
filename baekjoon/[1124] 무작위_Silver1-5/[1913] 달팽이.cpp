#include <bits/stdc++.h>
using namespace std;
int N, X, d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int table[1000][1000];
pair<int, int> lo;
void write() {
    int v = 2, dir = 0, cnt = 1, flag = 0;
    int x = N / 2 + 1, y = N / 2 + 1;
    bool end = 0;
    table[x][y] = 1;
    if (X == 1)
        lo.first = x, lo.second = y;
    while (!end) {
        for (int i = 0; i < cnt; i++) {
            x = x + d[dir][0];
            y = y + d[dir][1];
            if (v == X)
                lo.first = x, lo.second = y;
            table[x][y] = v++;
            if (v == N * N + 1) {
                end = 1;
                break;
            }
        }
        dir = (dir + 1) % 4;
        flag++;
        if (flag==2)
            cnt++, flag = 0;
    }

}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> X;
    write();
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << table[i][j] << " ";
        }
        cout << "\n";
    }
    cout << lo.first << " " << lo.second << "\n";
    return 0;
}