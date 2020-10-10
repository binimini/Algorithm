#include <bits/stdc++.h>
using namespace std;
int N,K,S;
bool know[401][401] = { 0 };
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    int a, b;
    for (int i = 0; i < K; i++) {
        cin >> a >> b;
        know[a][b] = 1;
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (know[i][k] && know[k][j])// i-> k k->j i->j
                    know[i][j] = 1;
            }
        }
    }
    cin >> S;
    for (int i = 0; i < S; i++) {
        cin >> a >> b;
        if (know[a][b])
            cout << "-1\n";
        else if (know[b][a])
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}