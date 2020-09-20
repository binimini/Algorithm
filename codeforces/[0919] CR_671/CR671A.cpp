#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        string s;
        cin >> N;
        cin >> s;
        int cntre = 0, cntro = 0;
        int cntbe = 0, cntbo = 0;
        for (int i = 0; i < s.size(); i++) {
            if (i % 2 == 0) {
                if ((s[i] - '0') % 2 == 0)
                    cntre++;
                else
                    cntro++;
            }
            else {
                if ((s[i] - '0') % 2 == 0)
                    cntbe++;
                else
                    cntbo++;
            }
        }
        N--;
        int r, b;
        if (N % 2 != 0) {
            r = N / 2 + 1;
            b = N / 2;
        }
        else
            r = N / 2, b = N / 2;
        int turn = 1;
        while (r > 0 || b > 0) {
            if (turn % 2 != 0) {
                if (cntre > 0)
                    cntre--;
                else
                    cntro--;
                r--;
            }
            else {
                if (cntbo > 0)
                    cntbo--;
                else
                    cntbe--;
                b--;
            }
            turn++;
        }
        if (cntro > 0|| cntbo>0)
            cout << 1 << "\n";
        else
            cout << 2 << "\n";
    }
    return 0;
}