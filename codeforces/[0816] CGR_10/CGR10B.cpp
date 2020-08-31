#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i<b; i++)
#define FAST std::ios_base::sync_with_stdio(0); cin.tie(0);
int T, N, arr[200000];
string K;
int main() {
    FAST;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N >> K;
        int M = -1000000001;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
            M = max(M, arr[i]);
        }
        for (int i = 0; i < N; i++) {
            arr[i] = M - arr[i];
        }
        if (int(K[K.size() - 1] - '0') % 2 == 1) {
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
            }
            cout << '\n';
        }
        else {
            int m = -1000000001;
            for (int i = 0; i < N; i++) {
                m = max(arr[i], m);
            }
            for (int i = 0; i < N; i++) {
                arr[i] = m-arr[i];
            }
            for (int i = 0; i < N; i++) {
                cout << arr[i] << " ";
            }
            cout << "\n";

        }
    }
    return 0;
}