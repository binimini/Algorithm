#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int N, M = 0, map[10][10] = { 0 };
bool check_min[19] = { 0 };
void dfs(int n, int cnt) {
    if (n > 2 * (N - 1)) return;
    if (cnt != 0) {
        M = max(M, cnt);
    }
    int x = n;
    while (x <= 2 * N - 2) {
        FOR(i, 0, N) {
            if (i<0 || i>N - 1 || x - i<0 || x - i>N - 1) continue;
            if (map[i][x - i] == 1 && check_min[2 * i - x + N - 1] == 0) {
                check_min[2 * i - x + N - 1] = 1;
                M = max(M, cnt + 1);
                dfs(x + 2, cnt + 1);
                check_min[2 * i - x + N - 1] = 0;
            }
        }
        x += 2;
    }
    
}
int main() {
    cin >> N;
    FOR(i, 0, N) {
        FOR(j, 0, N) {
            cin >> map[i][j];
        }
    }
    int result = 0;
    dfs(0, 0);
    result += M;
    M = 0;
    dfs(1, 0);
    result += M;
   
    cout << result<< "\n";
    return 0;
    
}