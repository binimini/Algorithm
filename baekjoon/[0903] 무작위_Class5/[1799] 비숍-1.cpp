#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int N, M = 0, map[10][10] = { 0 }, copy_map[10][10] = { 0 };
void dfs(int x, int y, int cnt) {
    vector<pair<int, int>> v;
    if (cnt != 0) {
        M = max(M, cnt);
        int sum = x + y;
        int min = x - y;
        FOR(i, 0, N) {//왼대각선 차
            if (i < 0 || i - min<0 || i>N - 1 || i - min>N - 1) continue;
            if (map[i][i - min] == 1) {
                map[i][i - min] = 0;
                v.push_back(make_pair(i, i - min));
            }
        }
        FOR(i, 0, N) {//오른대각선 합
            if (i < 0 || sum - i<0 || i>N - 1 || sum - i>N - 1) continue;
            if (map[i][sum - i] == 1) {
                map[i][sum - i] = 0;
                v.push_back(make_pair(i, sum - i));
            }
        }
    }
    int nx = x, ny = y;
    while (1) {
        if (ny == N)
            nx++, ny = 0;
        if (nx > N - 1)
            break;
        if (map[nx][ny] == 1) {
            map[nx][ny] = 0;
            dfs(nx, ny, cnt + 1);
            map[nx][ny] = 1;
        }
        ny++;
    }
    while (!v.empty()) {
        map[v.back().first][v.back().second] = 1;
        v.pop_back();
    }
}
int main() {
    cin >> N;
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            cin >> copy_map[i][j];
            map[i][j] = copy_map[i][j];
        }
    }
    int result = 0;
    int x = 0;
    while (x <= 2 * N - 2) {
        FOR(i, 0, N) {//오른대각선 합
            if (i < 0 || x- i<0 || i>N - 1 || x - i>N - 1) continue;
                map[i][x - i] = 0;
        }
        x += 2;
    }
    dfs(0, 0, 0);
    result += M;
    M = 0;
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            map[i][j] = copy_map[i][j];
        }
    }
    x = 1;
    while (x <= 2 * N - 2) {
        FOR(i, 0, N) {//오른대각선 합
            if (i < 0 || x - i<0 || i>N - 1 || x - i>N - 1) continue;
            map[i][x - i] = 0;
        }
        x += 2;
    }
    dfs(0, 0, 0);
    result += M;
    cout <<result << "\n";
    return 0;
}