#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, arr[10], map[8][8], move_cnt = 11, temp_map[8][8], d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };//위 오른쪽 아래 왼쪽
queue<pair<int, int>> q;
int x = 0;
void copy_map() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            temp_map[i][j] = map[i][j];
        }
    }
}
int move() {
    int i = 0;
    while (i < 10) {
        int check = 0;
        if (i + 1 > move_cnt)//i일때 틀림?
            return 11;
        if (arr[i] == 0) {//위
            for (int v = 0; v < N; v++) {
                for (int b = 0; b < M; b++) {
                    if (temp_map[v][b] == 1 || temp_map[v][b] == -1) {
                        q.push(make_pair(v, b));
                    }
                }
            }
        }
        else if (arr[i] == 1) {//오른쪽
            for (int v = M - 1; v >= 0; v--) {
                for (int b = 0; b < N; b++) {
                    if (temp_map[b][v] == 1 || temp_map[b][v] == -1) {
                        q.push(make_pair(b, v));
                    }
                }
            }
        }
        else if (arr[i] == 2) {//아래
            for (int v = N - 1; v >= 0; v--) {
                for (int b = 0; b < M; b++) {
                    if (temp_map[v][b] == 1 || temp_map[v][b] == -1) {
                        q.push(make_pair(v, b));
                    }
                }
            }
        }
        else {//왼쪽
            for (int v = 0; v < M; v++) {
                for (int b = 0; b < N; b++) {
                    if (temp_map[b][v] == 1 || temp_map[b][v] == -1) {
                        q.push(make_pair(b, v));
                    }
                }
            }
        }

        while (!q.empty()) {
            int x = q.front().first, y = q.front().second;
            q.pop();
            int nx = x + d[arr[i]][0], ny = y + d[arr[i]][1];
            while (temp_map[nx][ny] == 0) {
                if (nx<0 || ny<0 || nx>N - 1 || ny > M - 1) break;
                temp_map[nx][ny] = temp_map[x][y];
                temp_map[x][y] = 0;
                x = nx, y = ny, nx += d[arr[i]][0], ny += d[arr[i]][1];
            }
            if (nx<0 || ny<0 || nx>N - 1 || ny > M - 1) continue;
            if (temp_map[nx][ny] < 0) continue;
            if (temp_map[nx][ny] > 0) {
                if (temp_map[x][y] == -1) {
                    if (temp_map[nx][ny] == 2) {
                        return 11;
                    }
                }
                else if (temp_map[x][y] == 1) {
                    if (temp_map[nx][ny] == 2) {
                        check = 1;
                        temp_map[x][y] = 0;
                    }
                }
            }
        }
        if (check == 1) {
            return i + 1;
        }
        i++;
    }
    return 11;
}
void check_case(int cnt) {
    if (cnt == 10) {
        copy_map();
        move_cnt = min(move_cnt, move());
        return;
    }
    for (int i = 0; i < 4; i++) {
        arr[cnt] = i;
        check_case(cnt + 1);
    }
}
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    cin >> N >> M;
    N -= 2, M -= 2;
    string temp;
    cin >> temp;
    for (int i = 0; i < N; i++) {
        string r_temp;
        cin >> r_temp;
        for (int j = 0; j < M; j++) {
            if (r_temp[j + 1] == '.')
                map[i][j] = 0;
            else if (r_temp[j + 1] == '#')
                map[i][j] = -2;
            else if (r_temp[j + 1] == 'O')
                map[i][j] = 2;
            else if (r_temp[j + 1] == 'B') {
                map[i][j] = -1;
            }
            else {
                map[i][j] = 1;
            }
        }
    }
    cin >> temp;

    check_case(0);
    if (move_cnt == 11)
        cout << -1 << "\n";
    else
        cout << move_cnt << "\n";
}