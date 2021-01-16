#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int N, M, cnt = 0;
bool cheese[100][100], visited[100][100] = { 0 };
int check[100][100] = { 0 }, d[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
queue<pair<int, int>> q;

void bfs() {
    q.push(make_pair(0, 0));//시작 공기 (0,0)은 모든 접촉면 가장자리이므로 치즈와 닿을 일 없다
    visited[0][0] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx<0 || ny<0 || nx>N - 1 || ny>M - 1) continue;
            if (visited[nx][ny]) continue;
            if (cheese[nx][ny]) {//치즈이면 큐에 넣지않고 check값만 증가
                check[nx][ny]++;
                continue;
            }
            visited[nx][ny] = 1;
            q.push(make_pair(nx, ny));//방문안한 공기이면 큐에 넣이
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visited[i][j] = 0;//초기화 1
            if (check[i][j] >= 2) {//접촉면 2 이상이면 치즈 감소
                cheese[i][j] = 0;
                cnt--;
            }
            check[i][j] = 0;//초기화 2
        }
    }
}

int main() {
    FASTIO;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> cheese[i][j];
            if (cheese[i][j])
                cnt++;//치즈 개수
        }
    }
    int time = 0;
    while (cnt != 0) {//다 녹을 때까지
        time++;
        bfs();
    }
    cout << time;
    return 0;
}