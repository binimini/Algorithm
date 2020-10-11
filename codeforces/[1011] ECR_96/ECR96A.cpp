#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)

int T,N;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N;
        bool flag = 0;
        int X, Y, Z;
        for (int x = 0; x <= 333; x++) {
            if (flag)
                break;
            for (int y = 0; y <= 200; y++) {
                if ((N - x * 3 - y * 5) % 7 == 0&& (N - x * 3 - y * 5) / 7>=0) {
                    flag = 1;
                    X = x, Y = y, Z = (N - x * 3 - y * 5) / 7;
                    break;
                }
            }
        }
        if (flag)
            cout << X << " " << Y << " " << Z << "\n";
        else
            cout << -1 << "\n";
    }
    return 0;
}