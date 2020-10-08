#include <iostream>
#include <iomanip>
using namespace std;
int N, d[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
double cost[4], result = 0;
bool visited[29][29] = { 0 };//0-14-28
void dfs(int x, int y,int cnt, double value) {
    if (cnt == N) {
        result+=value;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nx = x + d[i][0];
        int ny = y + d[i][1];
        if (visited[nx][ny]) continue;
        visited[nx][ny] = 1;
        dfs(nx, ny, cnt + 1, value*cost[i]);
        visited[nx][ny] = 0;
    }
}
int main() {
    cin >> N;
    for (int i = 0; i < 4; i++) {
        cin >> cost[i];
        cost[i] /= 100;
    }
    visited[14][14] = 1;
    dfs(14, 14, 0, 1);
    cout << fixed << setprecision(10);
    cout <<result;
    return 0;
}