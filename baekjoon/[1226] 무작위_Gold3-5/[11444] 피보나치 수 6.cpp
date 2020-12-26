#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef vector<vector<ll>> matrix;
const ll MOD = 1000000007;
ll N;
matrix operator* (matrix& a, matrix& b) {
    ll size = a.size();
    matrix result(size, vector<ll>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            for (int k = 0; k < size; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
            result[i][j] = result[i][j] % MOD;
        }
    }
    return result;
}
matrix pow(matrix n, ll k) {
    matrix m;
    if (k == 0)
        return { {1,1},{1,1} };
    else if (k == 1)
        return n;
    else if (k % 2 == 0) {
        m = pow(n, k / 2);
        return m * m;
    }
    else if (k % 2 != 0) {
        m = pow(n, (k - 1) / 2);
        m = m * m;
        return m * n;
    }
}

int main() {
    FASTIO;
    cin >> N;
    matrix a = { {1,1},{1,0} };
    matrix result = pow(a, N - 1);
    if (N == 1)
        cout << 1;
    else
        cout << (result[1][0] + result[1][1]) % MOD;
    return 0;
}