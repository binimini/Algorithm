#include <bits/stdc++.h>
using namespace std;
int N;
bool arr[3072][3072 * 2 - 1] = { 0 };
void solve(int x, int y, int n) {
    if (n == 3) {
        arr[x][y] = 1;
        arr[x + 1][y - 1] = 1;
        arr[x + 1][y + 1] = 1;
        arr[x + 2][y - 2] = 1;
        arr[x + 2][y - 1] = 1;
        arr[x + 2][y] = 1;
        arr[x + 2][y + 1] = 1;
        arr[x + 2][y + 2] = 1;
        return;
    }
    solve(x, y, n / 2);
    solve(x + n / 2, y - n / 2, n / 2);
    solve(x + n / 2, y + n / 2, n / 2);
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    solve(0, (2*N-1)/2, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2 * N - 1; j++) {
            if (arr[i][j]) 
                cout << "*";
            else
                cout << " ";
        }
        cout << "\n";
    }
    return 0;
}