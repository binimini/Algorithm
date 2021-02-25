#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int d[9][2] = { {1,0},{0,1},{-1,0},{0,-1},{-1,-1},{-1,1},{1,-1},{1,1},{0,0} };
bool mapp[8][8] = { 0 };
queue<pair<pair<int, int>,bool>> q;
bool bfs() {
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        bool z = q.front().second;
        q.pop();
        if (!z) {
            if (mapp[x][y]) continue;
            for (int i = 0; i < 9; i++) {
                int nx = x + d[i][0];
                int ny = y + d[i][1];
                if (nx < 0 || nx>7 || ny < 0 || ny>7) continue;
                if (mapp[nx][ny]) continue;
                q.push({ {nx,ny},0 });
                if (nx == 0 && ny == 7)
                    return 1;
            }
        }
        else {
            if (x == 7) {
                mapp[x][y] = 0;
                continue;
            }
            else {
                mapp[x][y] = 0;
                mapp[x + 1][y] = 1;
                q.push({ {x + 1,y},1 });
            }
        }
    }
    return 0;
}
int main() {
    FASTIO;
    q.push({ {7,0},0 });
    char temp;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> temp;
            if (temp == '#') {
                mapp[i][j] = 1;
            }
        }
    }
    for (int i = 7; i >=0; i--) {
        for (int j = 0; j < 8; j++) {
            if (mapp[i][j])
                q.push({ {i,j},1 });
        }
    }
    cout <<bfs();

    return 0;
}