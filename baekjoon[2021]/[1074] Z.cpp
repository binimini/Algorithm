#include <bits/stdc++.h>
using namespace std;
int N, R, C;
bool flag = 0;
int cnt = 0;
void solve(int n, int r1, int c1, int r2, int c2) {
    if (flag)
        return;
    if (!(r1 <= R&&R <= r2 && c1 <= C&&C <= c2)) {
        cnt +=(int)pow(2,n) * (int)pow(2,n);
        return;
    }
    if (n==0&&R == r1 && C == c1) {
        flag = 1;
        cnt++;
        return;
    }
    int rh = (r1 + r2) / 2;
    int ch = (c1 + c2) / 2;
    solve(n - 1, r1, c1, rh, ch);
    solve(n - 1, r1, ch+1, rh, c2);
    solve(n - 1, rh+1, c1, r2, ch);
    solve(n - 1, rh+1, ch+1, r2, c2);
}
int main() {
    cin >> N >> R >> C;
    solve(N, 0, 0, (int)pow(2,N)-1, pow(2,N)-1);
    cout << cnt - 1;
    return 0;
}