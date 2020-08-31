#include <bits/stdc++.h>
using namespace std;
int n;
int mod = 1000000007;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    long long int x = 1, y = 1;
    for (int i = 1; i <= n; i++) {
        x = (x * i) % mod;
        if (i == n)
            break;
        y = (y * 2) % mod;
    }
    if (x - y < 0)
        cout << x - y + mod << "\n";
    else cout << x - y << "\n";
    return 0;
}