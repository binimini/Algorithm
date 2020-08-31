#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, map[51][51], temp_map[51][51], p_size = 0, v_size = 0, arr[13], maxi = 0, d[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
int v_cnt[100], v_cnt_sum = 250000;
pair<int, int> p[13], v[100];
queue<pair<int, int>> q;
void copy_map() {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            temp_map[i][j] = map[i][j];
        }
    }
}
int BFS() {
    int visited[51][51] = { 0 };
    while (1) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if (nx<1 || ny<1 || nx>N || ny>N) continue;
            if (visited[nx][ny]) continue;
            if (temp_map[nx][ny] == 2) {
                visited[nx][ny] = visited[x][y] + 1;
                return visited[nx][ny];
            }
            visited[nx][ny] = visited[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }

}
void DFS(int node, int cnt) {
    if (cnt == M) {
        copy_map();
        for (int i = 0; i < M; i++) {
            temp_map[p[arr[i]].first][p[arr[i]].second] = 2;
        }
        int sum = 0;
        for (int i = 0; i < v_size; i++) {
            q.push(make_pair(v[i].first, v[i].second));
            v_cnt[i] = BFS();
            sum += v_cnt[i];
            while (!q.empty()) {
                q.pop();
            }
            if (sum > v_cnt_sum)
                return;
        }
        v_cnt_sum = min(sum, v_cnt_sum);
        return;
    }
    for (int i = node; i < p_size; i++) {
        arr[cnt] = i;
        DFS(i + 1, cnt + 1);
    }
}
int main() {
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                v[v_size] = make_pair(i, j);//v 집 배열
                v_size++;
            }
            if (map[i][j] == 2) {
                p[p_size] = make_pair(i, j);//p 치킨 집 배열
                p_size++;
                map[i][j] = 0;
            }
        }
    }
    DFS(0, 0);
    cout << v_cnt_sum << '\n';
    return 0;
}