#include <bits/stdc++.h>
using namespace std;
int D, MOD = 1000000007;
long long int m[9][9], t[9][9] = { 0 }, to[9][9] = { 0 };
void mult() {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            t[i][j] = 0;
            for (int k = 1; k <= 8; k++) {
                t[i][j] = (t[i][j] + m[i][k] * m[k][j]) % MOD;
            }
        }
    }
}
void odd_mult() {
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            to[i][j] = 0;
            for (int k = 1; k <= 8; k++) {
                to[i][j] = (to[i][j] + t[i][k] * m[k][j]) % MOD;
            }
        }
    }
}
int main() {
    cin >> D;
    m[1][2] = 1, m[1][3] = 1;
    m[2][1] = 1, m[2][3] = 1, m[2][4] = 1;
    m[3][1] = 1, m[3][2] = 1, m[3][4] = 1, m[3][5] = 1;
    m[4][2] = 1, m[4][3] = 1, m[4][5] = 1, m[4][6] = 1;
    m[5][3] = 1, m[5][4] = 1, m[5][6] = 1, m[5][8] = 1;
    m[6][4] = 1, m[6][5] = 1, m[6][7] = 1;
    m[7][6] = 1, m[7][8] = 1;
    m[8][5] = 1, m[8][7] = 1;
    while (D != 1) {
        mult();
        if (D % 2 == 1) {
            odd_mult();
            for (int i = 1; i <= 8; i++) {
                for (int j = 1; j <= 8; j++) {
                    m[i][j] = to[i][j];
                    to[i][j] = 0;
                }
            }
        }
        else {
            for (int i = 1; i <= 8; i++) {
                for (int j = 1; j <= 8; j++) {
                    m[i][j] = t[i][j];
                    t[i][j] = 0;
                }
            }
        }
        D /= 2;
    }
    cout << m[1][1] << "\n";
    return 0;
}