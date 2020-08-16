#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i<b; i++)
#define FAST std::ios_base::sync_with_stdio(0); cin.tie(0);
int T, N, arr[200000];
int main() {
    FAST;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N;
        pair<int, int> M = { -1, 0 };
        FOR(i, 0, N) {
            cin >> arr[i];
            if (arr[i] > M.first) {
                M.first = arr[i];
                M.second = 1;
            }
            else if (arr[i] == M.first)
                M.second++;
        }
        if (N == M.second)
            cout << N << '\n';
        else cout << 1 << '\n';
    }
    return 0;
}