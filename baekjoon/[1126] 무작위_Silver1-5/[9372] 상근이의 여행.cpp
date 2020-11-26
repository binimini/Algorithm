#include <bits/stdc++.h>
using namespace std;
int T,N,M;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        int a, b;
        for (int i = 0; i < M; i++) {
            cin >> a >> b;
        }
        cout << N - 1 << "\n";
    }
    return 0;
}