#include <iostream>
using namespace std;
int N, M, X, Y, K, map[20][20] = { 0 }, d[5][2] = { {0,0},{0,1},{0,-1},{-1,0},{1,0} }, arr[4][3] = { 0 };
void move(int comm) {
    int new_arr[4][3] = { 0 };
    int nx = X + d[comm][0], ny = Y + d[comm][1];
    if (nx < 0 || ny < 0 || nx>N - 1 || ny>M - 1) return;
    if (comm == 1) {
        new_arr[1][0] = arr[1][1], new_arr[1][1] = arr[1][2], new_arr[1][2] = arr[3][1];
        new_arr[0][1] = arr[0][1], new_arr[2][1] = arr[2][1], new_arr[3][1] = arr[1][0];
    }
    else if (comm == 2) {
        new_arr[1][0] = arr[3][1], new_arr[1][1] = arr[1][0], new_arr[1][2] = arr[1][1];
        new_arr[0][1] = arr[0][1], new_arr[2][1] = arr[2][1], new_arr[3][1] = arr[1][2];
    }
    else if (comm == 3) {
        new_arr[1][1] = arr[0][1], new_arr[0][1] = arr[3][1], new_arr[2][1] = arr[1][1];
        new_arr[1][0] = arr[1][0], new_arr[1][2] = arr[1][2], new_arr[3][1] = arr[2][1];
    }
    else {
        new_arr[1][1] = arr[2][1], new_arr[0][1] = arr[1][1], new_arr[2][1] = arr[3][1];
        new_arr[1][0] = arr[1][0], new_arr[1][2] = arr[1][2], new_arr[3][1] = arr[0][1];
    }
    if (!map[nx][ny]) {
        map[nx][ny] = new_arr[1][1];
    }
    else {
        new_arr[1][1] = map[nx][ny];
        map[nx][ny] = 0;
    }
    X = nx, Y = ny;
    cout << new_arr[3][1] << "\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            arr[i][j] = new_arr[i][j];
        }
    }
}
int main() {
    cin >> N >> M >> X >> Y >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        int comm;
        cin >> comm;
        move(comm);
    }
    return 0;
}