#include <bits/stdc++.h>
using namespace std;
int N, d = 0;
pair<int, int> x = { 0,0 };
int cy[3][2] = { {0,1},{1,0},{1,1} };
bool mapp[32][32] = { 0 };
long long int dp[3][32][32];
long long int  dfs(int xx, int xy, int d) {
    int yx = xx + cy[d][0];
    int yy = xy + cy[d][1]; 
    if (xx<0 || xy<0 || xx>N - 1 || xy>N - 1 || yx<0 || yy<0 || yx>N - 1 || yy>N - 1) return 0;
    if (yx == N - 1 && yy == N - 1) return 1;
    
    if (dp[d][xx][xy] != -1)
        return dp[d][xx][xy];
   
    long long int& r = dp[d][xx][xy];
    r = 0;
    if (d == 0) {
        if (yy+1<N&&!mapp[yx][yy + 1]) {
            r += dfs(xx, xy + 1, d);
        }
        if (yx+1<N&&yy+1<N&&!mapp[yx + 1][yy + 1]&&!mapp[yx][yy+1]&&!mapp[yx+1][yy]) {
            r += dfs(xx, xy + 1, 2);
        }
    }
    else if (d == 1) {
        if (yx+1<N&&!mapp[yx + 1][yy]) {
            r += dfs(xx+1, xy, d);
        }
        if (yx+1<N&&yy+1<N&&!mapp[yx + 1][yy + 1] && !mapp[yx][yy + 1] && !mapp[yx + 1][yy]) {
            r += dfs(xx+1, xy, 2);
        }
        
    }
    else if (d == 2) {
        if (yx+1<N&&yy+1<N&&!mapp[yx + 1][yy + 1] && !mapp[yx][yy + 1] && !mapp[yx + 1][yy]) {
            r += dfs(xx+1,xy+1,d);
        }
        if (yx+1<N&&!mapp[yx + 1][yy]) {
            r += dfs(xx+1, xy+1, 1);
        }
        if (yy+1<N&&!mapp[yx][yy + 1]) {
            r += dfs(xx+1, xy+1, 0);
        }
    }
    return r;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < 3; k++) {
                dp[k][i][j] = -1;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> mapp[i][j];
        }
    }
    cout <<dfs(0,0,0);
    return 0;
}