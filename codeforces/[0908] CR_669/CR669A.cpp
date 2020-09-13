#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i<b; i++)
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T, N;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N;
        int temp;
        int cnt0 = 0, cnt1 = 0;
        FOR(i, 0, N) {
            cin >> temp;
            if (temp == 1)
                cnt1++;
            else if (temp == 0)
                cnt0++;
        }

        if (cnt0 >= N / 2) {
            cout << N / 2 << "\n";
            for (int i = 0; i < N / 2; i++) {
                cout << 0 << " ";
            }
            cout << '\n';
        }
        else {
            if ((N / 2) % 2 == 0) {
                cout << N / 2 << "\n";
                for (int i = 0; i < N / 2; i++) {
                    cout << 1 << " ";
                }
                cout << '\n';
            }
            else {
                cout << N / 2 + 1 << "\n";
                for (int i = 0; i < N / 2 + 1; i++) {
                    cout << 1 << " ";
                }
                cout << "\n";
            }
        }
    }
    return 0;
}