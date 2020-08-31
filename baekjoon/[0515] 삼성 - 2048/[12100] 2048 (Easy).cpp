#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, map[20][20], temp_map[20][20], visited[20][20] = { 0 }, d[4][2] = { {1,0},{0,1},{-1,0},{0,-1} }, arr[5], max_cnt = 0;
queue<pair<int, int>> q;
int move() {
    int i = 0;
    while (i < 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                visited[i][j] = 0;
            }
        }
        if (arr[i] == 0) {//아래
            for (int i = N - 1; i >= 0; i--) {
                for (int j = 0; j < N; j++) {
                    if (temp_map[i][j]) {
                        q.push(make_pair(i, j));
                    }
                }
            }
        }
        else if (arr[i] == 1) {//오른쪽
            for (int i = N - 1; i >= 0; i--) {
                for (int j = 0; j < N; j++) {
                    if (temp_map[j][i]) {
                        q.push(make_pair(j, i));
                    }
                }
            }
        }
        else if (arr[i] == 2) {//위
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (temp_map[i][j]) {
                        q.push(make_pair(i, j));
                    }
                }
            }
        }
        else {//왼쪽
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (temp_map[j][i]) {
                        q.push(make_pair(j, i));
                    }
                }
            }
        }
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            int nx = x + d[arr[i]][0];
            int ny = y + d[arr[i]][1];
            while (1) {
                if (nx<0 || ny<0 || nx>N - 1 || ny>N - 1) break;
                if (temp_map[nx][ny] == temp_map[x][y]) {
                    if (!visited[nx][ny]) {
                        temp_map[nx][ny] += temp_map[x][y];
                        visited[nx][ny] = 1;
                        temp_map[x][y] = 0;
                    }
                    break;
                }
                if (temp_map[nx][ny]) break;
                if (!temp_map[nx][ny]) {
                    temp_map[nx][ny] = temp_map[x][y];
                    temp_map[x][y] = 0;
                    x = nx, y = ny;
                    nx += d[arr[i]][0], ny += d[arr[i]][1];
                }
            }
        }
        i++;
    }
    int maax = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            maax = max(temp_map[i][j], maax);
        }
    }
    return maax;
}
void copy_map() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp_map[i][j] = map[i][j];
        }
    }
}
void check_case(int cnt) {
    if (cnt == 5) {
        copy_map();
        max_cnt = max(max_cnt, move());
        return;
    }
    for (int i = 0; i < 5; i++) {
        arr[cnt] = i;
        check_case(cnt + 1);
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j])
                q.push(make_pair(i, j));
        }
    }
    check_case(0);
    cout << max_cnt << '\n';

    return 0;
}