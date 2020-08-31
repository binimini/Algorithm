#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, map[50][50], temp_map[50][50], visited[50][50] = { 0 }, not_virus = 0, d[4][2] = { {-1,0},{0,-1},{1,0},{0,1} }, Mini = 9999, temp = 0, arr[10];
pair<int, int> virus_p[10];
queue<pair<int, int>> q;
void copy_map() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp_map[i][j] = map[i][j];
            visited[i][j] = 0;
        }
    }
}
int BFS() {
    int maxi = 1;
    int cnt = not_virus;
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (!cnt) {
                while (!q.empty()) q.pop();
                return maxi - 1;
            }
            int nx = x + d[i][0], ny = y + d[i][1];
            if (nx<0 || ny<0 || nx>N - 1 || ny>N - 1) continue;
            if (visited[nx][ny]) continue;
            if (temp_map[nx][ny] == 2) {
                visited[nx][ny] = visited[x][y] + 1;
                maxi = max(visited[nx][ny], maxi);
                q.push(make_pair(nx, ny));
            }
            if (!temp_map[nx][ny]) {
                temp_map[nx][ny] = 1;
                visited[nx][ny] = visited[x][y] + 1;
                maxi = max(visited[nx][ny], maxi);
                cnt--;
                q.push(make_pair(nx, ny));

            }
        }
    }
    if (!cnt)
        return maxi - 1;
    else return 1000;
}
void DFS(int node, int cnt) {
    if (cnt == M) {
        copy_map();
        for (int i = 0; i < M; i++) {
            visited[virus_p[arr[i]].first][virus_p[arr[i]].second] = 1;
            temp_map[virus_p[arr[i]].first][virus_p[arr[i]].second] = 0;
            q.push(make_pair(virus_p[arr[i]].first, virus_p[arr[i]].second));
        }
        Mini = min(Mini, BFS());
        return;
    }
    for (int i = node; i < temp; i++) {
        arr[cnt] = i;
        DFS(i + 1, cnt + 1);
    }

}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                virus_p[temp] = make_pair(i, j);
                temp++;
            }
            else if (!map[i][j]) not_virus++;
        }
    }
    DFS(0, 0);
    if (Mini == 1000)
        cout << -1 << '\n';
    else
        cout << Mini << '\n';
    return 0;
}