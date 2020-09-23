#include <bits/stdc++.h>
using namespace std;
int N, M, H, cnt = 300;
bool to[11][31] = { 0 }, flag = 0;
void dfs(int xx, int cnt) {
    bool check = 1;
    if (cnt == 0) {
        int x;
        for (int i = 1; i <= N; i++) {
            x = i;
            for (int j = 1; j <= H; j++) {
                if (x<N&&to[x][j])
                    x++;
                else if (x>1&&to[x - 1][j])
                    x--;
            }
            if (x != i) {
                check = 0;
                break;
            }
        }
        if (check) {
            flag = true;
        }
        return;
    }

    for (int i = xx; i < N; i++) {
        for (int j = 1; j <= H; j++) {
            if (to[i][j]) continue;
            if (i > 1 && to[i - 1][j]) continue;
            if (i < N && to[i + 1][j]) continue;
            to[i][j] = 1;
            dfs(i, cnt - 1);
            if (flag)
                return;
            to[i][j] = 0;
        }
    }
    return;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> H;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        to[b][a] = 1;
    }
    for (int i = 0; i <= 3; i++) {
        dfs(1,i);
        if (flag) {
            cnt = i;
            break;
        }
    }
    if (cnt > 3)
        cout << -1;
    else
        cout << cnt;
    return 0;
}