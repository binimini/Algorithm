#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T;
long long int X, Y, K;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> X >> Y >> K;
        long long int temp = K*(Y+1)-1;
        long long int cnt = K;
        cnt += temp / (X - 1);
        if (temp % (X - 1) != 0)
            cnt++;
        cout << cnt << "\n";

    }
    return 0;
}