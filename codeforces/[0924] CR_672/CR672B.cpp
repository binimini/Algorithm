#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for(int i = a; i<b; i++)
int T, N;
long long int cnt[32] = { 0 };
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        for (int i = 0; i < 32; i++) {
            cnt[i] = 0;
        }
        cin >> N;
        int temp;
        long long int result = 0;
        FOR(i, 0, N) {
            cin >> temp;
            int k = 0;
            while (1) {
                if (temp < int(pow(2, k)))
                    break;
                k++;
            }
            k--;
            cnt[k]++;
        }
        for (int i = 0; i < 32; i++) {
            if (cnt[i] >= 2) {
                result += cnt[i] * (cnt[i] - 1) / 2;
            }
        }
        cout << result << "\n";
    }
    return 0;
}