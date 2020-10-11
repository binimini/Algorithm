#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int R, N, RESULT = 0;
int dp[100000][2];
tuple<int, int, int> info[100000];
void dfs(int x, int y, int n, int t, int r) {
    cout << x << " " << y << " " << n << " " << t << " " << r << "\n";
    if (n >= N) {
        RESULT = max(RESULT, r);
        return;
    }
    if (N - 1 - (n - 1) <= RESULT)
        return;
    int nt = get<0>(info[n]);
    int nx = get<1>(info[n]);
    int ny = get<2>(info[n]);
    if (nt - t >= abs(nx - x) + abs(ny - y)) {
        dfs(nx, ny, n + 1, nt, r+1);
    }
    dfs(x, y, n + 1, t, r);

}
int main() {
    FASTIO;
    cin >> R >> N;
    int t, x, y;
    FOR(i, 0, N) {
        cin >> t >> x >> y;
        info[i] = make_tuple(t, x, y);
    }
    dfs(1, 1, 0, 0, 0);
    cout << RESULT;
    return 0;
}