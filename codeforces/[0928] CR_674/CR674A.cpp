#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N, X;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N >> X;
        if (N == 1 || N == 2)
            cout << 1 << "\n";
        else if (N == 3)
            cout << 2 << "\n";
        else {
            cout << (N - 3) / X + 2 << "\n";
        }
    }
    return 0;
}