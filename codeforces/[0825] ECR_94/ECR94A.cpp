#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N;
        char temp;
        int key;
        for (int i = 0; i < 2 * N - 1; i++) {
            cin >> temp;
            if (i == N - 1)
                key = temp-'0';
        }
        for (int i = 0; i < N; i++) {
            cout << key;
        }
        cout << '\n';
    }
    return 0;
}