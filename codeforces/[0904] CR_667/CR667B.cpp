#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, a, b, x, y, n;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> a >> b >> x >> y >> n;
        if (a - min(a - x, n) < b - min(b - y, n)) {
            int d = min(a - x, n);
            a -= d;
            n -= d;
            if (n != 0)
                b -= min(b - y, n);
        }
        else {
            int d = min(b - y, n);
            b -= d;
            n -= d;
            if (n != 0)
                a -= min(a - x, n);
        }
        long long int result = a;
        result *= b;
        cout << result << "\n";
    }

    return 0;
}