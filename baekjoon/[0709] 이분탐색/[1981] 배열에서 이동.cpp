#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, arr[101][101], mini = 201, maxi = -1, R, CH = 0, d[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
bool BFS(int key) {
    int arr_min, arr_max;
    for (int i = 0; i <= key; i++) {
        queue<pair<int, int>> q;
        bool visited[101][101] = { 0 };
        q.push(make_pair(1, 1));
        visited[1][1] = 1;
        arr_min = arr[1][1] - key + i, arr_max = arr[1][1] + i;
        if (arr_min < mini) continue;
        if (arr_max > maxi) continue;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if (x == N && y == N)
                return true;
            for (int i = 0; i < 4; i++) {
                int nx = x + d[i][0];
                int ny = y + d[i][1];
                if (nx<1 || ny<1 || nx>N || ny>N) continue;
                if (visited[nx][ny]) continue;
                if (arr[nx][ny] > arr_max || arr[nx][ny] < arr_min) continue;
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
    return false;
}
int binary_search(int left, int right) {
    int mid;
    while (right - left >= 0) {
        mid = (right + left) / 2;
        if (BFS(mid)) {
            R = min(R, mid);
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return R;
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
            mini = min(mini, arr[i][j]);
            maxi = max(maxi, arr[i][j]);
        }
    }
    R = maxi - mini;
    cout << binary_search(0, maxi - mini);
    return 0;
}