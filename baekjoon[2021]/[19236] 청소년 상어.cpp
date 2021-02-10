#include <bits/stdc++.h>
using namespace std;
int res = 0, d[9][2] = { {0,0},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1},{-1,1} };
pair<pair<int, int>, int> fish[17];
int mapp[4][4];
void shark(int x, int y, int score) {
    pair<pair<int, int>, int> temp_fish[17];
    int temp_mapp[4][4];
    int direc = fish[mapp[x][y]].second;
    int nscore = score + mapp[x][y];
    for (int i = 1; i <= 16; i++) {
        temp_fish[i].first = fish[i].first;
        temp_fish[i].second = fish[i].second;
    }
    fish[mapp[x][y]].second = 0;//생선방향
    res = max(res, nscore);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            temp_mapp[i][j] = mapp[i][j];
        }
    }
    mapp[x][y] = 0;//상어가 먹은 칸
 
    int flag = 0, temp;
    for (int i = 1; i <= 16; i++) {//물고기 움직임 (물고기 위치, 방향 변경될 수 있음)
        if (fish[i].second == 0) continue;
        flag = 0;
        while (flag < 8) {
            flag++;
            int x_ = fish[i].first.first;
            int y_ = fish[i].first.second;
            int xx = x_ + d[fish[i].second][0];
            int yy = y_ + d[fish[i].second][1];
            if ((xx < 0 || xx>3 || yy < 0 || yy>3)|| (xx == x && yy == y)) {
                fish[i].second = (fish[i].second + 1) % 9;
                if (fish[i].second == 0) fish[i].second++;
                continue;
            }
            else {
                temp = mapp[xx][yy];
                mapp[xx][yy] = i;
                mapp[x_][y_] = temp;
                fish[i].first.first = xx;
                fish[i].first.second = yy;
                fish[temp].first.first = x_;
                fish[temp].first.second = y_;
                break;
            }
        }

    }
    for (int i = 1; i <= 4; i++) {
        int nx = x + i*d[direc][0];
        int ny = y + i*d[direc][1];
        if (nx < 0 || nx>3 || ny < 0 || ny>3)
            break;
        if (mapp[nx][ny] == 0) continue;
        shark(nx, ny, nscore);

    }
    for (int i = 1; i <= 16; i++) {
        fish[i].first = temp_fish[i].first;
        fish[i].second = temp_fish[i].second;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            mapp[i][j] = temp_mapp[i][j];
        }
    }
}
int main() {
    int a, b;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> a >> b;
            fish[a].first = { i,j };
            fish[a].second = b;
            mapp[i][j] = a;
        }
    }
    shark(0, 0, 0);
    cout << res;
    return 0;
}