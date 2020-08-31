#include <iostream>
#include <queue>
using namespace std;
int R, C, T, map[50][50], spread_map[50][50] = { 0 }, d[4][2] = { {-1,0},{0,-1},{1,0},{0,1} }, sum;
queue<pair<int, int>> q;
pair<int, int> cleaner[2];
void spread() {
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if (nx<0 || ny<0 || nx>R - 1 || ny>C - 1) continue;
            if (nx == cleaner[0].first && ny == cleaner[0].second) continue;
            if (nx == cleaner[1].first && ny == cleaner[1].second) continue;
            spread_map[nx][ny] += map[x][y] / 5;
            cnt++;
        }
        map[x][y] -= map[x][y] / 5 * cnt;
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (spread_map[i][j]) { map[i][j] += spread_map[i][j]; spread_map[i][j] = 0; }
            if (j != 0 && j != C - 1 && i != 0 && i != R - 1 && i != cleaner[0].first && i != cleaner[1].first && map[i][j] > 0) { q.push(make_pair(i, j)); }
        }
    }
}
void cleaner_operate() {
    int pre = 0;
    int x_0 = cleaner[0].first, y_0 = cleaner[0].second;
    while (y_0 < C - 1) {
        y_0++;
        int temp = map[x_0][y_0];
        map[x_0][y_0] = pre;
        if (map[x_0][y_0]) q.push(make_pair(x_0, y_0));
        pre = temp;
    }
    while (x_0 > 0) {
        x_0--;
        int temp = map[x_0][y_0];
        map[x_0][y_0] = pre;
        if (map[x_0][y_0]) q.push(make_pair(x_0, y_0));
        pre = temp;
    }
    while (y_0 > 0) {
        y_0--;
        int temp = map[x_0][y_0];
        map[x_0][y_0] = pre;
        if (map[x_0][y_0]) q.push(make_pair(x_0, y_0));
        pre = temp;
    }
    while (x_0 < cleaner[0].first - 1) {
        x_0++;
        int temp = map[x_0][y_0];
        map[x_0][y_0] = pre;
        if (map[x_0][y_0]) q.push(make_pair(x_0, y_0));
        pre = temp;
    }
    pre = 0;
    int x_1 = cleaner[1].first, y_1 = cleaner[1].second;
    while (y_1 < C - 1) {
        y_1++;
        int temp = map[x_1][y_1];
        map[x_1][y_1] = pre;
        if (map[x_1][y_1]) q.push(make_pair(x_1, y_1));
        pre = temp;
    }
    while (x_1 < R - 1) {
        x_1++;
        int temp = map[x_1][y_1];
        map[x_1][y_1] = pre;
        if (map[x_1][y_1]) q.push(make_pair(x_1, y_1));
        pre = temp;
    }
    while (y_1 > 0) {
        y_1--;
        int temp = map[x_1][y_1];
        map[x_1][y_1] = pre;
        if (map[x_1][y_1]) q.push(make_pair(x_1, y_1));
        pre = temp;
    }
    while (x_1 > cleaner[1].first + 1) {
        x_1--;
        int temp = map[x_1][y_1];
        map[x_1][y_1] = pre;
        if (map[x_1][y_1]) q.push(make_pair(x_1, y_1));
        pre = temp;
    }
}
int main() {
    cin >> R >> C >> T;
    int temp = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> map[i][j];
            if (map[i][j] == -1) {
                cleaner[temp] = make_pair(i, j);
                map[i][j] = 0;
                temp++;
            }
            else if (map[i][j]) {
                q.push(make_pair(i, j));
            }
        }
    }
    for (int x = 0; x < T; x++) {
        spread();
        cleaner_operate();
    }
    sum = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (map[i][j]) {
                sum += map[i][j];
            }
        }
    }
    cout << sum << "\n";
    return 0;
}