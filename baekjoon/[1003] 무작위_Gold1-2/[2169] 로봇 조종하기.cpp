#include <iostream>
#include <algorithm>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
#define FOR(i,a,b) for(int i = a; i<b; i++)
int N, M, INF = -100000001, d[3][2] = { {0,1},{0,-1},{1,0} };
int map[1000][1000];
int dp[1000][1000][3];
bool visited[1000][1000] = { 0 };
int find_dp(int x, int y, int direc) {
    if (x == N - 1 && y == M - 1)
        return map[N-1][M-1];
    if (dp[x][y][direc] != INF)
        return dp[x][y][direc];//왼쪽 오른쪽 시 가능한 경우 한 가지 경우만 따지고 
    //가능한 경우 확인 없이 반환하는 경우 있을 수 있나?
    //방향별로 배열 값 디피 필요
    int& r = dp[x][y][direc];
    visited[x][y] = 1;//한번 방문한 칸을 다른 방향으로 재방문하는 것 방지?
    for (int i = 0; i < 3; i++) {
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1) continue;
        if (visited[nx][ny]) continue;
        r = max(r,find_dp(nx, ny, i)+map[x][y]);
    }
    visited[x][y] = 0;//백트래킹이랑 다른 점??
    return r;
}
int main() {
    FASTIO;
    cin >> N >> M;
    FOR(i, 0, N) {
        FOR(j, 0, M) {
            cin >> map[i][j];
            FOR(k, 0, 3) {
                dp[i][j][k] = INF;
            }
        }
    }
    cout <<find_dp(0, 0, 0)<<"\n";
    return 0;
}