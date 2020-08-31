#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, X;
string S;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> S >> X;
        string W = "";
        string NS = "";
        for (int i = 0; i < S.size(); i++) {
            W += '1';
            NS += '0';
        }
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '0') {
                if (i + X < S.size()) {
                    W[i + X] = '0';
                }
                if (i - X >= 0) {
                    W[i - X] = '0';
                }
            }
        }
        for (int i = 0; i < S.size(); i++) {
            if (i+X<S.size()) {
                if (W[i+X]=='1')
                    NS[i] = '1';
            }
            if (i - X >= 0) {
                if (W[i-X]=='1')
                    NS[i] = '1';
            }
        }
        if (NS == S) {
            cout << W << '\n';
        }
        else cout << -1 << '\n';
    }
    return 0;
}