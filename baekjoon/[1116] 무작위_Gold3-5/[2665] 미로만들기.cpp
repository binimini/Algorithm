#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
int N, visited[51][51], d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} }, INF = 2500;
bool mapp[51][51];
priority_queue<pair<int,pair<int,int>>> pq;
void dijkstra() {
    visited[1][1] = 0;
    pq.push(make_pair(0, make_pair(1, 1)));
    while (!pq.empty()) {
        int c = -pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if (visited[x][y] < c) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            int nc = c;
            if (nx<1 || nx>N || ny<1 || ny>N) continue;
            if (!mapp[nx][ny]) nc = c + 1;
            if (visited[nx][ny] > nc) {
                visited[nx][ny] = nc;
                pq.push(make_pair(-nc, make_pair(nx, ny)));
            }
        }

    }
}
int main() {
    FASTIO;
    cin >> N;
    char temp;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            visited[i][j] = INF;
            cin >> temp;
            mapp[i][j] = temp - '0';
        }
    }
    dijkstra();
    cout << visited[N][N];
    return 0;
}