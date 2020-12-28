#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
bool d[11] = { 0 };
int status = 0, N, R = 0;
int main() {
    FASTIO;
    cin >> N;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        if ((status & (1 << a)) == 0) {
            status |= (1 << a);
            d[a] = b;
        }
        else {
            if (d[a] != b) {
                R++;
                d[a] = b;
            }
        }
    }
    cout << R;
    return 0;
}