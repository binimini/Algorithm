#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int arr[500][500] = { 0 }, N, M, cnt = 0;
int check_tetris(int x, int y) {
    int check_cnt = 0, test_cnt[19] = { 0 };
    if (y + 3 <= M - 1) {
        for (int i = 0; i < 4; i++) {
            test_cnt[0] += arr[x][y + i];
        }
    }
    if (x + 3 <= N - 1) {
        for (int i = 0; i < 4; i++) {
            test_cnt[1] += arr[x + i][y];
        }
    }
    if (x + 1 <= N - 1 && y + 1 <= M - 1) {
        test_cnt[2] = arr[x][y] + arr[x][y + 1] + arr[x + 1][y] + arr[x + 1][y + 1];
    }
    if (x + 2 <= N - 1 && y + 1 <= M - 1) {
        test_cnt[3] = arr[x][y] + arr[x + 1][y] + arr[x + 2][y] + arr[x + 2][y + 1];
        test_cnt[4] = arr[x][y] + arr[x][y + 1] + arr[x + 1][y + 1] + arr[x + 2][y + 1];
        test_cnt[5] = arr[x][y] + arr[x + 1][y] + arr[x + 1][y + 1] + arr[x + 2][y + 1];
        test_cnt[9] = arr[x][y] + arr[x + 1][y] + arr[x + 2][y] + arr[x + 1][y + 1];
        test_cnt[15] = arr[x][y] + arr[x + 1][y] + arr[x + 2][y] + arr[x][y + 1];

    }
    if (x + 1 <= N - 1 && y + 2 <= M - 1) {
        test_cnt[6] = arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x + 1][y];
        test_cnt[7] = arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x + 1][y + 1];
        test_cnt[8] = arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x + 1][y + 2];
        test_cnt[16] = arr[x][y] + arr[x + 1][y] + arr[x + 1][y + 1] + arr[x + 1][y + 2];
        test_cnt[18] = arr[x][y] + arr[x][y + 1] + arr[x + 1][y + 1] + arr[x + 1][y + 2];
    }
    if (x - 1 >= 0 && y + 2 <= M - 1) {
        test_cnt[10] = arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x - 1][y + 1];
        test_cnt[11] = arr[x][y] + arr[x][y + 1] + arr[x][y + 2] + arr[x - 1][y + 2];
        test_cnt[12] = arr[x][y] + arr[x][y + 1] + arr[x - 1][y + 1] + arr[x - 1][y + 2];
    }
    if (x - 1 >= 0 && x + 1 <= N - 1 && y + 1 <= M - 1) {
        test_cnt[13] = arr[x][y] + arr[x - 1][y + 1] + arr[x][y + 1] + arr[x + 1][y + 1];
        test_cnt[14] = arr[x][y] + arr[x][y + 1] + arr[x - 1][y + 1] + arr[x + 1][y];
    }
    if (x - 2 >= 0 && y + 1 <= M - 1) {
        test_cnt[17] = arr[x][y] + arr[x][y + 1] + arr[x - 1][y + 1] + arr[x - 2][y + 1];
    }
    for (int i = 0; i < 19; i++) {
        check_cnt = max(check_cnt, test_cnt[i]);
    }
    return check_cnt;
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cnt = max(cnt, check_tetris(i, j));
        }
    }
    cout << cnt << "\n";
    return 0;
}