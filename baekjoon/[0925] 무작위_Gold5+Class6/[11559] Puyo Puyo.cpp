#include <iostream>
#include <queue>
#include <vector>
using namespace std;
char map[12][6];
bool visited[12][6] = { 0 }, flag = true;
int d[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
queue<pair<int,int>> q;
void remove(char color) {
    vector<pair<int, int>> v;
    v.push_back(make_pair(q.front().first, q.front().second));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx < 0 || nx>11 || ny < 0 || ny>5) continue;
            if (visited[nx][ny]) continue;
            if (map[nx][ny] != color) continue;
            visited[nx][ny] = 1;
            q.push(make_pair(nx,ny));
            v.push_back(make_pair(nx, ny));
        }
    }
    if (v.size() >= 4) {
        flag = true;
        while (!v.empty()) {
            map[v.back().first][v.back().second] = '.';
            v.pop_back();
        }
    }
}
void gravity() {
    vector<char> v;
    for (int j = 0; j < 6; j++) {
        for (int i = 0; i < 12; i++) {
            if (map[i][j] != '.') {
                v.push_back(map[i][j]);
                map[i][j] = '.';
            }
        }
        int idx = 11;
        while (!v.empty()) {
            map[idx][j] = v.back();
            v.pop_back();
            idx--;
        }
    }
}
int main() {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 6; j++) {
            cin >> map[i][j];
        }
    }
    int cnt = 0;
    while (flag) {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                visited[i][j] = 0;
            }
        }
        flag = false;
        cnt++;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (map[i][j] != '.') {
                    visited[i][j] = 1;
                    q.push(make_pair(i, j));
                    remove(map[i][j]);

                }
            }
        }
        gravity();
    }
    cout << cnt - 1 << '\n';
    return 0;
}