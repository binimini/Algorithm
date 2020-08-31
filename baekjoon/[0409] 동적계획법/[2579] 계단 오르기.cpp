#include <iostream>
#include <algorithm>
using namespace std;
int DP[301][2], N, arr[301], c[301][2];
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    DP[1][0] = arr[1];
    DP[2][0] = arr[2] + arr[1];
    DP[2][1] = arr[2];
    c[1][0] = 0;
    c[2][0] = 1;
    for (int i = 3; i <= N; i++) {
        if (DP[i - 1][0] > DP[i - 1][1])
            c[i][0] += c[i - 1][0] + 1;
        DP[i][0] = arr[i] + max(DP[i - 1][0], DP[i - 1][1]);
        DP[i][1] = arr[i] + max(DP[i - 2][0], DP[i - 2][1]);
        if (DP[i][0] > DP[i][1])
            c[i][0]++;
        if (c[i][0] >= 2) {
            DP[i][0] = arr[i] + DP[i - 1][1];
            c[i][0] = 1;
        }
    }
    cout << max(DP[N][0], DP[N][1]) << "\n";
    return 0;
}