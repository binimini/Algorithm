#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T,N, K;
int arr[1000];
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N >> K;
        int m = 10001;
        int idx = 0;
        FOR(i, 0, N) {
            cin >> arr[i];
            if (arr[i] < m) {
                m = arr[i];
                idx = i;
            }
        }
        int cnt = 0;
        FOR(i, 0, N) {
            if (i == idx) continue;
            else {
                if (arr[i] == K) continue;
                cnt += (K - arr[i]) / m;
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}