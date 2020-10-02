#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int N, M, INF = 10001, d[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
bool map[100][100];
int visited[100][100];
priority_queue < pair<int, pair<int, int>>> pq;
void dijkstra() {
    while (!pq.empty()) {
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        int c = -pq.top().first;
        pq.pop();
        if (visited[x][y] < c) continue;

        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1) continue;
            int nc = c;
            if (map[nx][ny])
                nc++;
            if (visited[nx][ny] > nc) {
                visited[nx][ny] = nc;
                pq.push(make_pair(-nc, make_pair(nx, ny)));
            }
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            char temp;
            cin >> temp;
            map[i][j] = temp - '0';
            visited[i][j] = INF;
        }
    }
    pq.push({ 0,{0,0} });
    visited[0][0] = 0;//처음위치 거리 초기화
    dijkstra();
    cout << visited[N-1][M-1]<< "\n";
    return 0;
}