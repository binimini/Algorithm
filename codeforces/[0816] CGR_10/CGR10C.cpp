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
        int temp = 0;
        long long int cnt = 0;
        FOR(i, 0, N) {
            cin >> arr[i];
            if (temp > arr[i]) {
                cnt += temp;
                cnt -= arr[i];
            }
            temp = arr[i];
        }
        cout << cnt << '\n';
    }
    return 0;
}