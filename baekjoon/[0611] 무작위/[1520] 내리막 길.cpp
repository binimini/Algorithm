#include <iostream>
using namespace std;
int M, N, cnt = 0, map[500][500], d[4][2] = { {-1,0},{0,-1},{1,0},{0,1} }, dp[500][500];
int DFS(int x, int y) {
    int check = 0;
    if (x == M - 1 && y == N - 1) {//끝에 도달한 경우 return 1
        cnt++, dp[x][y] = 1;
    }
    if (dp[x][y] != -1) return dp[x][y];//이미 값이 있는 경우 return 값
    else {
        dp[x][y] = 0;//도착 불가능한 경로 방문체크 
        for (int i = 0; i < 4; i++) {//값 존재하지않아 파고들 떄
            int nx = x + d[i][0], ny = y + d[i][1];
            if (nx<0 || ny<0 || nx>M - 1 || ny>N - 1) continue;
            if (map[x][y] <= map[nx][ny]) continue;//조건 체크
            dp[x][y] += DFS(nx, ny);//nx,ny에 안 존재하면 -> 반복
            //존재하면 -> 더하고 다른 방향 확인
        }//백트래킹마저 하기
        return dp[x][y];//이전 경로에 더해짐
    }
    return cnt;
}
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    cout << DFS(0, 0);
    return 0;
}