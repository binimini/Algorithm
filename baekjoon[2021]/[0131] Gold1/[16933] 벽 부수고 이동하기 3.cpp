#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
int N, M, K, visited[1001][1001][11][2] = { 0 }, d[5][2] = { {1,0},{0,1},{-1,0},{0,-1},{0,0} }, INF = 987654321;
bool mapp[1000][1000] = { 0 };
queue<pair<pair<int, int>,pair<int, bool>>> q;
int bfs() {
    visited[0][0][0][0] = 1;//start with night!! so nk is day
    q.push({ {0,0}, {0,0} });
    
    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int z = q.front().second.first;
        bool k = q.front().second.second;
        q.pop();
        
        for (int i = 0; i < 5; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            int nz = z;
            bool nk = !k;//day <-> night
            
            if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1) continue;
            if (i!=4&&mapp[nx][ny]) {//is wall //if stay in place, don't check(else same wall twice break)!!!
                if (z == K || !nk) continue;//breaks K wall or not day
                nz++;//else breaks wall
            }
            if (visited[nx][ny][nz][nk]) continue;//already checked //bfs is queue always smaller dist first
            
            visited[nx][ny][nz][nk] = visited[x][y][z][k] + 1;
            q.push({ {nx,ny}, {nz,nk} });
        }
    }
    
    int res = INF;//result value (we find minimum so initialize with maximum
    for (int i = 0; i <= K; i++) {//find minimum dist 
        for (int j = 0; j < 2; j++) {
            if (visited[N-1][M-1][i][j] != 0)
                res = min(res, visited[N-1][M-1][i][j]);
        }
    }
    if (res == INF)//impossible case
        return -1;
    else
        return res;
}
int main() {
    FASTIO;//input
    cin >> N >> M >> K;
    char temp;
    for (int i = 0; i < N; i++) {//(0,0) - (N-1,M-1)
        for (int j = 0; j < M; j++) {
            cin >> temp;
            if (temp=='1')//char value is always true in bool
                mapp[i][j] = 1;
        }
    }

    cout <<bfs();
    return 0;
}