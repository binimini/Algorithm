#include <iostream>
using namespace std;
int N, map[17][17], cnt = 0;
pair<int, int> p[2] = { {1,1},{1,2} };
bool move(int i, int d) {
    int x = p[i].first, y = p[i].second;
    if (d == 0) {
        int nx = x, ny = y + 1;
        if (ny<1 || ny>N) return false;
        if (map[nx][ny]) return false;
        p[i].second = ny;
    }
    else if (d == 1) {
        int nx = x + 1, ny = y;
        if (nx<1 || nx>N) return false;
        if (map[nx][ny]) return false;
        p[i].first = nx;
    }
    else if (d == 2) {
        int nx = x + 1, ny = y + 1;
        if (ny<1 || ny>N || nx<1 || nx>N) return false;
        if (map[nx][ny]) return false;
        if (map[nx][y]) return false;
        if (map[x][ny]) return false;
        p[i].first = nx, p[i].second = ny;
    }
    return true;
}
void DFS() {
    if (p[1].first == N && p[1].second == N) {
        cnt++;
        return;
    }
    if (p[0].first == p[1].first) {//가로
        pair<int, int> temp[2];
        temp[0].first = p[0].first;
        temp[0].second = p[0].second;
        temp[1].first = p[1].first;
        temp[1].second = p[1].second;
        if (move(0, 0)) {
            if (move(1, 0))
                DFS();
        }
        p[0].first = temp[0].first;
        p[0].second = temp[0].second;
        p[1].first = temp[1].first;
        p[1].second = temp[1].second;
        if (!move(0, 0)) return;
        else if (!move(1, 2)) return;
        else DFS();
        return;
    }
    else if (p[0].second == p[1].second) {//세로
        pair<int, int> temp[2];
        temp[0].first = p[0].first;
        temp[0].second = p[0].second;
        temp[1].first = p[1].first;
        temp[1].second = p[1].second;
        if (move(0, 1)) {
            if (move(1, 1))
                DFS();
        }
        p[0].first = temp[0].first;
        p[0].second = temp[0].second;
        p[1].first = temp[1].first;
        p[1].second = temp[1].second;
        if (!move(0, 1)) return;
        else if (!move(1, 2))return;
        else DFS();
        return;
    }
    else {//대각
        pair<int, int> temp[2];
        temp[0].first = p[0].first;
        temp[0].second = p[0].second;
        temp[1].first = p[1].first;
        temp[1].second = p[1].second;
        if (move(0, 2)) {
            if (move(1, 2))
                DFS();
        }
        p[0].first = temp[0].first;
        p[0].second = temp[0].second;
        p[1].first = temp[1].first;
        p[1].second = temp[1].second;
        if (move(0, 2)) {
            if (move(1, 0))
                DFS();
        }
        p[0].first = temp[0].first;
        p[0].second = temp[0].second;
        p[1].first = temp[1].first;
        p[1].second = temp[1].second;
        if (!move(0, 2)) return;
        else if (!move(1, 1)) return;
        else DFS();
        return;
    }
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }
    DFS();
    cout << cnt;
    return 0;
}