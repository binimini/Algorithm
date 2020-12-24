#include <bits/stdc++.h>
using namespace std;
int W, H, RESULT = 500000, cnt = 0;
int arr[20][20], d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int dp[20][20][1<<10];
int ch[20][20];
queue<pair<pair<int, int>,int>> q;
void solve() {
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            int nz = z;
            if (nx<0 || ny<0 || nx>W - 1 || ny>H - 1) continue;
            if (arr[nx][ny] == -1) continue;
            if (arr[nx][ny] == 1) nz |= (1 << ch[nx][ny]);
            if (dp[nx][ny][nz] != -1) {
                if (dp[x][y][z] + 1 < dp[nx][ny][nz]) {
                    dp[nx][ny][nz] = dp[x][y][z] + 1;
                    q.push(make_pair(make_pair(nx, ny), nz));
                    if (nz == ((1 << cnt) - 1))
                        RESULT = min(RESULT, dp[nx][ny][nz]);
                }
            }
            else {
                dp[nx][ny][nz] = dp[x][y][z] + 1;
                q.push(make_pair(make_pair(nx, ny), nz));
                if (nz == ((1 << cnt )- 1))
                RESULT = min(RESULT, dp[nx][ny][nz]);
            }


        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while (1) {
        cin >> H >> W;
        if (!W && !H)
            break;
        memset(dp, -1, sizeof(dp));
        memset(ch, -1, sizeof(ch));
        RESULT = 500000;
        char temp;
        cnt = 0;
        for (int i = 0; i < W; i++) {
            for (int j = 0; j < H; j++) {
                cin >> temp;
                if (temp == '*') {
                    arr[i][j] = 1;
                    ch[i][j] = cnt;
                    cnt++;
                }
                else if (temp == 'x')
                    arr[i][j] = -1;
                else if (temp == 'o') {
                    arr[i][j] = 0;
                    q.push(make_pair(make_pair(i, j),0));
                    dp[i][j][0] = 0;
                }
                else
                    arr[i][j] = 0;
            }
        }
        solve();
        if (RESULT == 500000)
            cout << -1 << "\n";
        else
            cout << RESULT << "\n";
    }
    return 0;
}