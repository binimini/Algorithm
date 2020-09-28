#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N, M;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N >> M;
        bool right = 0;
        int tl, tr, bl, br;
        FOR(i, 0, N) {
            cin >> tl >> tr;
            cin >> bl >> br;
            if (bl == tr)
                right = 1;
        }
        if (M % 2 != 0)
            cout << "NO\n";
        else if (right)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}