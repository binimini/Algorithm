#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
#define FOR(i,a,b) for(int i = a; i<b; i++)
int N, M, d[4][2] = {{ -1,0 }, { 1,0 }, { 0,-1 }, { 0,1 }};
bool map[1000][1000] = { 0 }, CH = 0;
int visited[1000][1000][2] = { 0 };
queue<tuple<int, int, bool>> q;
void BFS() {
    while (!q.empty()) {
        int x = get<0>(q.front());
        int y = get<1>(q.front());
        int z = get<2>(q.front());
        if (x == N - 1 && y == M - 1) {
            cout << visited[x][y][z];
            CH = 1;
            return;
        }
        q.pop();
        FOR(i,0,4) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1) continue;
            if (map[nx][ny] && !z) {
                if (!visited[nx][ny][1]) {
                    visited[nx][ny][1] = visited[x][y][0] + 1;
                    q.push(make_tuple(nx, ny, 1));
                }
            }
            if (map[nx][ny]) continue;
            if (visited[nx][ny][z]) continue;
            visited[nx][ny][z] = visited[x][y][z] + 1;
            if (nx == N - 1 && ny == M - 1) {
                cout << visited[nx][ny][z];
                CH = 1;
                return;
            }
            q.push(make_tuple(nx, ny, z));
        }
    }
}
int main() {//벽 부수고 이동하기
    FASTIO;
    cin >> N >> M;
    char temp;
    FOR(i,0,N){
        FOR(j, 0, M) {
            cin >> temp;
            map[i][j] = temp - '0';
        }
    }
    q.push(make_tuple(0,0,0));
    visited[0][0][0] = 1;
    BFS();
    if (!CH)
        cout << -1;
    return 0;
}