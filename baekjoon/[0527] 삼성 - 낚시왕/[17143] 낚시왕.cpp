#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;
int R, C, M, r, c, s, direc, z, size_sum = 0, map[100][100] = { 0 }, temp_map[100][100] = { 0 }, lo = -1, d[5][2] = { {0,0},{-1,0},{1,0},{0,1},{-1,0} };
pair<int, int> info[10001];
queue<pair<int, int>> q;
void move() {
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        int temp_d = info[map[x][y]].first, temp_s = info[map[x][y]].second;
        int nx = x, ny = y;
        while (temp_s != 0) {
            if (temp_d == 1) {
                if (temp_s >= nx) { temp_d = 2, temp_s -= nx, nx = 0; continue; }
                else { nx -= temp_s; break; }
            }
            else if (temp_d == 2) {
                if (temp_s >= R - 1 - nx) { temp_d = 1, temp_s -= R - 1 - nx, nx = R - 1; continue; }
                else { nx += temp_s; break; }
            }
            else if (temp_d == 3) {
                if (temp_s >= C - 1 - ny) { temp_d = 4, temp_s -= C - 1 - ny, ny = C - 1; continue; }
                else { ny += temp_s; break; }
            }
            else {
                if (temp_s >= ny) { temp_d = 3, temp_s -= ny, ny = 0; continue; }
                else { ny -= temp_s; break; }
            }
        }
        info[map[x][y]].first = temp_d;
        temp_map[nx][ny] = max(map[x][y], temp_map[nx][ny]);
        map[x][y] = 0;
    }
    for (int w = 0; w < R; w++) {
        for (int e = 0; e < C; e++) {
            if (temp_map[w][e]) {
                map[w][e] = temp_map[w][e];
                q.push(make_pair(w, e));
                temp_map[w][e] = 0;
            }
        }
    }
}
int main() {
    cin.tie(NULL);
    cin >> R >> C >> M;
    for (int i = 0; i < M; i++) {
        cin >> r >> c >> s >> direc >> z;
        map[r - 1][c - 1] = z;
        info[z] = make_pair(direc, s);
        q.push(make_pair(r - 1, c - 1));
    }
    for (int i = 0; i < C; i++) {
        if (q.empty()) break;
        lo++;
        for (int j = 0; j < R; j++) {
            if (map[j][lo]) {
                size_sum += map[j][lo];
                map[j][lo] = 0;
                break;
            }
        }
        move();
    }
    cout << size_sum << "\n";
    return 0;
}