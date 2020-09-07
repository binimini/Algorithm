#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N;
int arr[100];
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0,T) {
        cin >> N;
        FOR(i, 0, N) {
            cin >> arr[i];
        }
        for (int i = N - 1; i >= 0; i--) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}