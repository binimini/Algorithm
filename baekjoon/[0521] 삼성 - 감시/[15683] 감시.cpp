#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, arr[8][8], temp_arr[8][8], p_size = 0, m = 64, d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }, v[64][3];
void copy_map() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            temp_arr[i][j] = arr[i][j];
        }
    }
}
int check_safezone() {
    for (int i = 0; i < p_size; i++) {
        int x = v[i][0], y = v[i][1];
        switch (temp_arr[v[i][0]][v[i][1]]) {
        case 5: {
            for (int k = 0; k < 4; k++) {
                int nx = x, ny = y;
                int dir = (v[i][2] + k) % 4;
                while (1) {
                    nx += d[dir][0], ny += d[dir][1];
                    if (nx<0 || ny<0 || nx>N - 1 || ny>M - 1) break;
                    if (temp_arr[nx][ny] == 6) break;
                    if (!temp_arr[nx][ny]) {
                        temp_arr[nx][ny] = -1;
                    }
                }
            }
            break;
        }
        case 4: {
            for (int k = 0; k < 3; k++) {
                int nx = x, ny = y;
                int dir = (v[i][2] + k) % 4;
                while (1) {
                    nx += d[dir][0], ny += d[dir][1];
                    if (nx<0 || ny<0 || nx>N - 1 || ny>M - 1) break;
                    if (temp_arr[nx][ny] == 6) break;
                    if (!temp_arr[nx][ny]) {
                        temp_arr[nx][ny] = -1;
                    }
                }
            }
            break;
        }
        case 3: {
            for (int k = 0; k < 2; k++) {
                int nx = x, ny = y;
                int dir = (v[i][2] + k) % 4;
                while (1) {
                    nx += d[dir][0], ny += d[dir][1];
                    if (nx<0 || ny<0 || nx>N - 1 || ny>M - 1) break;
                    if (temp_arr[nx][ny] == 6) break;
                    if (!temp_arr[nx][ny]) {
                        temp_arr[nx][ny] = -1;
                    }
                }
            }
            break;
        }
        case 2: {
            int nx = x, ny = y;
            int dir = (v[i][2] + 2) % 4;
            while (1) {
                nx += d[dir][0], ny += d[dir][1];
                if (nx<0 || ny<0 || nx>N - 1 || ny>M - 1) break;
                if (temp_arr[nx][ny] == 6) break;
                if (!temp_arr[nx][ny]) {
                    temp_arr[nx][ny] = -1;
                }
            }
            nx = x, ny = y;
            dir = v[i][2];
            while (1) {
                nx += d[dir][0], ny += d[dir][1];
                if (nx<0 || ny<0 || nx>N - 1 || ny>M - 1) break;
                if (temp_arr[nx][ny] == 6) break;
                if (!temp_arr[nx][ny]) {
                    temp_arr[nx][ny] = -1;
                }
            }
            break;
        }
        case 1: {
            int nx = x, ny = y;
            while (1) {
                nx += d[v[i][2]][0], ny += d[v[i][2]][1];
                if (nx<0 || ny<0 || nx>N - 1 || ny>M - 1) break;
                if (temp_arr[nx][ny] == 6) break;
                if (!temp_arr[nx][ny]) {
                    temp_arr[nx][ny] = -1;
                }
            }
            break;
        }
        }
    }
    int safe_zone = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!temp_arr[i][j]) safe_zone++;
        }
    }
    return safe_zone;
}
void DFS(int cnt) {
    if (cnt == p_size) {
        copy_map();
        m = min(m, check_safezone());
        return;
    }
    int for_cnt = 1;
    if (arr[v[cnt][0]][v[cnt][1]] == 1) for_cnt += 3;
    else if (arr[v[cnt][0]][v[cnt][1]] == 2) for_cnt += 1;
    else if (arr[v[cnt][0]][v[cnt][1]] == 3) for_cnt += 3;
    else for_cnt += 3;
    for (int i = 0; i < for_cnt; i++) {
        v[cnt][2] = (v[cnt][2] + 1) % 4;
        DFS(cnt + 1);
    }
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
            if (arr[i][j] > 0 && arr[i][j] != 6) {
                v[p_size][0] = i, v[p_size][1] = j, v[p_size][2] = 0;
                p_size++;
            }
        }
    }

    DFS(0);
    cout << m << '\n';
    return 0;
}