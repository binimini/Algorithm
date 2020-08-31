#include <iostream>
#include <queue>
using namespace std;
int N, map[20][20], time = 0, fish_e[6] = { 0 }, sh_size = 2, visited[20][20] = { 0 }, d[4][2] = { {-1,0},{0,-1},{0,1},{1,0} }, eaten = 0, cnt = 0;
int eatable[20][20] = { 0 };
queue<pair<int, int>> q;
void BFS() {
    int check = 10000;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (visited[x][y] > check - 1) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx < 0 || ny<0 || nx>N - 1 || ny>N - 1) continue;
            if (visited[nx][ny]) continue;
            if (!map[nx][ny]) {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = visited[x][y] + 1;
                continue;
            }
            if (map[nx][ny]) {
                if (sh_size < map[nx][ny]) continue;
                if (sh_size == map[nx][ny]) {
                    q.push(make_pair(nx, ny));
                    visited[nx][ny] = visited[x][y] + 1;
                    continue;
                }
                else {
                    visited[nx][ny] = visited[x][y] + 1;
                    if (visited[nx][ny] > check) continue;
                    eatable[nx][ny] = 1;
                    check = visited[nx][ny];
                }
            }
        }
    }
    if (check > 0 && check != 10000) {
        int e_x, e_y;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (eatable[i][j]) {
                    e_x = i, e_y = j;
                    i = N, j = N;
                }
            }
        }
        fish_e[map[e_x][e_y] - 1]--, eaten++;
        if (eaten == sh_size)
            sh_size++, eaten = 0;
        map[e_x][e_y] = 0;

        while (!q.empty()) {
            q.pop();
        }
        q.push(make_pair(e_x, e_y));
        cnt += visited[e_x][e_y] - 1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                visited[i][j] = 0;
                eatable[i][j] = 0;
            }
        }
        visited[e_x][e_y] = 1;
        return;
    }

}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                q.push(make_pair(i, j));
                visited[i][j] = 1;
                map[i][j] = 0;
                continue;
            }
            fish_e[map[i][j] - 1]++;
        }
    }
    while (1) {
        int sum = 0;
        int temp = 0;
        if (sh_size > 7)
            temp = 5;
        else temp = sh_size - 2;
        for (int i = 0; i <= temp; i++) {
            sum += fish_e[i];
        }
        if (sum == 0) {
            cout << cnt << '\n';
            break;
        }
        BFS();
    }
    return 0;
}