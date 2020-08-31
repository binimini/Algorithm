#include <iostream>
#include <vector>
using namespace std;
int N, K, map[12][12], lo[10][3], direc[5][2] = { {0,0}, {0,1},{0,-1},{-1,0},{1,0} }, check = 0, repeat1 = 0, repeat2 = 0;
vector<vector<vector<int>>> v(12, vector<vector<int>>(12, vector<int>()));
void move(int cnt) {

    int x = lo[cnt][1], y = lo[cnt][2], d = lo[cnt][0];
    int nx = x + direc[d][0], ny = y + direc[d][1];
    if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1) {
        if (d == 1) lo[cnt][0] = 2;
        else if (d == 2) lo[cnt][0] = 1;
        else if (d == 3) lo[cnt][0] = 4;
        else lo[cnt][0] = 3;
        nx = x + direc[lo[cnt][0]][0], ny = y + direc[lo[cnt][0]][1];
        if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1) return;
        else { repeat1 = 1; }
    }
    else if (map[nx][ny] == 0) {
        int arr[5];
        int size = v[x][y].size();
        for (int i = size - 1; i >= 0; i--) {
            arr[i] = v[x][y].back();
            v[x][y].pop_back();
        }
        for (int i = 0; i < size; i++) {
            v[nx][ny].push_back(arr[i]);
            lo[arr[i]][1] = nx, lo[arr[i]][2] = ny;
        }
        if (v[nx][ny].size() >= 4) { check = 1; return; }
    }
    else if (map[nx][ny] == 1) {
        int size = v[x][y].size();
        for (int i = 0; i < size; i++) {
            v[nx][ny].push_back(v[x][y].back());
            lo[v[x][y].back()][1] = nx, lo[v[x][y].back()][2] = ny;
            v[x][y].pop_back();
        }
        if (v[nx][ny].size() >= 4) { check = 1; return; }
    }
    else {
        if (d == 1) lo[cnt][0] = 2;
        else if (d == 2) lo[cnt][0] = 1;
        else if (d == 3) lo[cnt][0] = 4;
        else lo[cnt][0] = 3;
        nx = x + direc[lo[cnt][0]][0], ny = y + direc[lo[cnt][0]][1];
        if (nx<0 || nx>N - 1 || ny<0 || ny>N - 1) return;
        else {
            repeat2++;
        }
    }
    if (repeat2 >= 2) { repeat2 = 0; return; }
    if (repeat1 == 1) {
        repeat1 = 0;
        move(cnt);
        return;
    }
    if (repeat2) {
        repeat2++;
        move(cnt);
        return;
    }
}
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        int r, c, d;
        cin >> r >> c >> d;
        v[r - 1][c - 1].push_back(i);
        lo[i][1] = r - 1, lo[i][2] = c - 1, lo[i][0] = d;
    }
    int turn = 0;
    while (turn <= 1000) {
        turn++;
        for (int i = 0; i < K; i++) {
            move(i);
        }
        if (check == 1) {
            cout << turn << "\n";
            break;
        }

    }
    if (check == 0)
        cout << -1 << '\n';
    return 0;
}