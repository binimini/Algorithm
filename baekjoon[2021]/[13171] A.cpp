#include <bits/stdc++.h>
using namespace std;
long long int A, AA = 1, X, XX;
int p[65];
int MOD = 1000000007;
int main() {
    cin >> A >> X;
    int i = 1;
    XX = 1;
    AA = A % MOD;
    p[0] = 1;
    while (XX <= X) {
        p[i] = AA % MOD;
        XX *= 2;
        AA = ((AA % MOD) * (AA % MOD)) % MOD;
        i++;
    }
    XX /= 2;
    i--;
    long long int xx = 0, ans = 1;//long long int!!!
    while (xx != X) {
        if (xx+XX <= X) {
            xx += XX;
            ans = ((ans % MOD) * (p[i] % MOD)) % MOD;
        }
        XX /= 2;
        i--;
    }
    cout << ans;

    return 0;
}