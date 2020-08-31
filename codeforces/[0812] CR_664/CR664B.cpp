#include <bits/stdc++.h>
using namespace std;
int N, M, x, y;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M >> x >> y;
    for (int i = x; i > 0; i--) {
        cout << i << " " << y << "\n";
    }
    for (int i = x + 1; i <= N; i++) {
        cout << i << " " << y << '\n';
    }
    int nx = N;
    for (int j = y + 1; j <= M; j++) {
        if (nx == N) {
            while (nx >= 1) {
                cout << nx << " " << j << "\n";
                if (nx == 1)
                    break;
                nx--;
            }
        }
        else if (nx == 1) {
            while (nx <= N) {
                cout << nx << " " << j << "\n";
                if (nx == N)
                    break;
                nx++;
            }
        }
    }
    for (int j = y - 1; j > 0; j--) {
        if (nx == N) {
            while (nx >= 1) {
                cout << nx << " " << j << "\n";
                if (nx == 1)
                    break;
                nx--;
            }
        }
        else if (nx == 1) {
            while (nx <= N) {
                cout << nx << " " << j << "\n";
                if (nx == N)
                    break;
                nx++;
            }
        }
    }
    return 0;
}