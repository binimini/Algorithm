#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, a,b;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> a >> b;
        int differ = abs(b - a);
        if (differ == 0)
            cout << 0<<'\n';
        else if (differ % 10 != 0)
            cout << differ / 10 + 1 << "\n";
        else cout << differ / 10<<'\n';
    }
    return 0;
}