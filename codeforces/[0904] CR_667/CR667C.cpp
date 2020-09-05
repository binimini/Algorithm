#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, a, b, x, y, n;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> n >> x >> y;
        for (int i = n-1; i > 0; i--) {
            if ((y - x) % i == 0) {
                a = i;
                break;
            }
        }
        b = (y - x) / a;
        int remain = n - 1 - a;
        if (remain == 0) {
            for (int i = 0; i < n; i++) {
                cout << x << " ";
                x += b;
            }
            cout << '\n';
        }
        else {
            int nx = x - min(x / b, remain) * b;// x y사이 b가 최소 계산 대상 아니라 남은 remain == y-x-a*b 가 대상..
            if (nx == 0)
                nx += b;
            for (int i = 0; i < n; i++) {
                cout << nx << " ";
                nx += b;
            }
            cout << "\n";
        }
    }

    return 0;
}