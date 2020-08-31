#include <bits/stdc++.h>
using namespace std;
int T, N;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        int temp;
        int a, b, c;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            if (i == 0)
                a = temp;
            else if (i == 1)
                b = temp;
            else if (i == N - 1)
                c = temp;
        }
        if (a + b <= c)
            cout << 1 << " " << 2 << " " << N << "\n";
        else cout << -1 << "\n";
    }
    return 0;
}