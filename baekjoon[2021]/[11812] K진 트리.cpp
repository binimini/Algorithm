#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
long long int N;
long long int K, Q;
int main() {
    cin >> N >> K >> Q;
    FASTIO;
    long long int x, y;
    for (int i = 0; i < Q; i++) {
        cin >> x >> y;
        if (K == 1) {
            cout <<abs(x - y)<<"\n";
        }
        else {
            x += K - 2;
            y += K - 2;
            int cnt = 0;
            while (x != y) {
                if (x > y) {
                    x = (x / K) + K - 2;
                    cnt++;
                }
                else if (y>x) {
                    y = (y / K) + K - 2;
                    cnt++;
                }
            }
            cout << cnt << "\n";
        }
    }
    return 0;
}