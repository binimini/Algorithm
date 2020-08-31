#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, is_cnt = 0, route_cnt = 0, min_dist = 150, sum = 0, d[4][2] = { {-1,0},{0,-1},{1,0},{0,1} };
int map[10][10], map_visited[10][10] = { 0 }, arr[15], is_visited[7], edge[7][7] = { 0 }, temp_edge[7][7];
pair<int, int> route_info[15];
queue<pair<int, int>> q;
queue<int> move_q;
int move() {
    int sum = 0;
    move_q.push(1);
    while (!move_q.empty()) {
        int x = move_q.front();
        move_q.pop();
        is_visited[x] = 1;
        for (int i = 1; i < x; i++) {
            if (temp_edge[i][x]) {
                if (!is_visited[i]) {
                    move_q.push(i);
                    sum += temp_edge[i][x];
                }
            }
        }
        for (int i = x + 1; i <= is_cnt; i++) {
            if (temp_edge[x][i]) {
                if (!is_visited[i]) {
                    move_q.push(i);
                    sum += temp_edge[x][i];
                }
            }
        }
    }
    for (int i = 1; i <= is_cnt; i++) {
        if (!is_visited[i]) return 150;
    }
    return sum;
}
void copy_edge() {
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            temp_edge[i][j] = edge[i][j];
        }
    }

}
void route_DFS(int cnt) {
    if (cnt == route_cnt) {
        copy_edge();
        for (int i = 1; i <= is_cnt; i++) {
            is_visited[i] = 0;
        }
        for (int i = 0; i < cnt; i++) {
            if (!arr[i]) temp_edge[route_info[i].first][route_info[i].second] = 0;
        }
        min_dist = min(min_dist, move());
        return;
    }
    for (int i = 0; i < 2; i++) {
        arr[cnt] = i;
        route_DFS(cnt + 1);
    }
}
void make_route(int x, int y) {
    int my = map_visited[x][y];
    for (int i = 0; i < 4; i++) {
        int dist = 0;
        int nx = x, ny = y;
        while (1) {
            dist++;
            nx += d[i][0], ny += d[i][1];
            if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1) break;
            if (map_visited[nx][ny] == my) break;
            if (map_visited[nx][ny]) {
                int dest = map_visited[nx][ny];
                if (dist - 1 <= 1) break;
                if (edge[min(dest, my)][max(dest, my)] <= 1) edge[min(dest, my)][max(dest, my)] = dist - 1;
                else edge[min(dest, my)][max(dest, my)] = min(dist - 1, edge[min(dest, my)][max(dest, my)]);
                break;
            }

        }

    }
}
void is_BFS() {
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0], ny = y + d[i][1];
            if (nx<0 || ny<0 || nx>N - 1 || ny>M - 1) continue;
            if (!map[nx][ny]) continue;
            if (map_visited[nx][ny]) continue;
            map_visited[nx][ny] = is_cnt;
            q.push(make_pair(nx, ny));
        }
    }
}
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!map[i][j]) continue;
            if (map_visited[i][j]) continue;
            is_cnt++;
            q.push(make_pair(i, j));
            map_visited[i][j] = is_cnt;
            is_BFS();

        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map_visited[i][j])	make_route(i, j);
        }
    }
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) {
            if (edge[i][j]) {
                route_info[route_cnt].first = i, route_info[route_cnt].second = j;
                route_cnt++;
            }
        }
    }
    route_DFS(0);
    if (min_dist == 150) cout << -1;
    else cout << min_dist;
    return 0;
}