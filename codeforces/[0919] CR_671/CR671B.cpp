#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T;
long long int N;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N;
        int cnt = 0;
        long long int temp = 1;
        while (1) {
            if (N < temp * (temp + 1) / 2)
                break;
            else
                N -= temp * (temp + 1) / 2;
            cnt++;
            temp += temp + 1;
        }
        cout << cnt << "\n";
    }
    return 0;
}