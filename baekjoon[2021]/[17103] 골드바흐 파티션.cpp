#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T,N;
bool notprime[1000001] = { 0 };
int main() {
    notprime[0] = 1, notprime[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        if (notprime[i]) continue;
        for (int j = i * 2; j <= 1000000; j += i) {
            notprime[j] = 1;
        }
    }
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        int cnt = 0;
        for (int i = 2; i <= N/2; i++) {
            if (notprime[i] || notprime[N-i]) continue;
            cnt++;
        }
        cout << cnt << "\n";
    }
    return 0;
}