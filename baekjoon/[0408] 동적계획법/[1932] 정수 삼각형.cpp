#include <iostream>
#include <algorithm>
using namespace std;
int arr[501][501], DP[501][501];
int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        DP[i][1] = DP[i - 1][1] + arr[i][1];
        for (int j = 2; j < i; j++) {
            DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]) + arr[i][j];
        }
        DP[i][i] = DP[i - 1][i - 1] + arr[i][i];
    }
    int m = 0;
    for (int i = 1; i <= N; i++) {
        m = max(DP[N][i], m);
    }
    cout << m << "\n";
    return 0;
}