#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T, M, N;
int i = 0, j = 0;
void cycle(int m, int n, int left, int right) {
    int c = 0;
    while (!(i == m - 1 && j == n - 1)) {
        if (j == left|| j == right) {
            c++, i++;
            cout << "(" << i << "," << j << ")\n";
        }
        if (c % 2 != 0)
            j--;
        else if (c % 2 == 0)
            j++;
        cout << "(" << i << "," << j << ")\n";
    }
}
int main() {
    FASTIO;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> M >> N;
        cout << 1 << "\n";
        if (M % 2 == 0) {
            i = -1, j = N - 1;
            cycle(M, N, 0, N - 1);
        }
        else {
            for (int i = M - 1; i > 0; i--) {
                cout << "(" << i << "," << 0 << ")\n";
            }
            for (int i = 0; i <= N - 1; i++) {
                cout << "(" << 0 << "," << i << ")\n";
            }
            i = 0, j = N - 1;
            cycle(M, N, 1, N - 1);
        }
    }
    return 0;
}