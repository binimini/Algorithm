#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, K, A[50][50], temp_A[50][50], arr[6], visited[6] = { 0 }, arr_info[6][3], m_sum = 5001, sum = 5001;
queue<int> q;
void copy_A() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            temp_A[i][j] = A[i][j];
        }
    }
}
void rotate(int k) {
    int x = arr_info[k][1], y = arr_info[k][2], s = arr_info[k][0];
    for (int i = s; i > 0; i--) {
        int check = 0, d_y = 1, d_x = 1;
        int nx = x - i, ny = y - i;
        q.push(temp_A[nx][ny]);
        while (1) {
            if (check) nx += d_x;
            else ny += d_y;
            q.push(temp_A[nx][ny]);
            temp_A[nx][ny] = q.front();
            q.pop();

            if (ny == y + i && check == 0) check = 1;
            else if (nx == x + i && check == 1) check = 0, d_y = -1;
            else if (ny == y - i && check == 0) check = 1, d_x = -1;
            else if (nx == x - i && check == 1) break;
        }
        q.pop();
    }
}
void DFS(int cnt) {
    if (cnt == K) {
        copy_A();
        for (int i = 0; i < K; i++) {
            rotate(arr[i]);
        }
        int temp = 0;
        for (int i = 0; i < N; i++) {
            temp = 0;
            for (int j = 0; j < M; j++) {
                temp += temp_A[i][j];
                if (temp > sum) break;
            }
            sum = min(sum, temp);
        }
        return;
    }
    for (int i = 0; i < K; i++) {
        if (visited[i]) continue;
        arr[cnt] = i;
        visited[i] = 1;
        DFS(cnt + 1);
        visited[i] = 0;
    }
}
int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        cin >> arr_info[i][1] >> arr_info[i][2] >> arr_info[i][0];
        arr_info[i][1]--, arr_info[i][2]--;
    }
    DFS(0);
    cout << sum;
    return 0;
}