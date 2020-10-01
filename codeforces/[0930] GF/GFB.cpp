#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N, K;
int a[100];
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N >> K;
        int cnt = 0;
        int differ = 0;
        int pre = -1;
        bool oneflag = 1;
        FOR(i, 0, N) {
            cin >> a[i];
            if (pre != -1 && pre != a[i])
                differ++;
            if (differ == K - 1&&K!=1)
                cnt++, differ = 0;
            pre = a[i];
        }
        if (differ != 0) {
            cnt++;
            oneflag = 0;
        }
        if (K != 1) {
            if (cnt == 0 && oneflag)
                cout << 1 << "\n";
            else
                cout << cnt << "\n";
        }
        else {
            if (oneflag)
                cout << 1 << "\n";
            else
                cout << -1 << "\n";
        }
    }
    return 0;
}