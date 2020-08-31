#include <iostream>
#include <algorithm>
using namespace std;
int arr[10001], DP[10001][2], N;
int main() {
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    DP[1][0] = arr[1];
    DP[2][0] = arr[1] + arr[2];
    DP[2][1] = arr[1];
    for (int i = 3; i <= N; i++) {
        DP[i][1] = max(DP[i - 1][0], DP[i - 1][1]);
        DP[i][0] = max(arr[i - 1] + DP[i - 2][1], DP[i - 1][1]) + arr[i];
    }
    cout << max(DP[N][0], DP[N][1]) << "\n";
    return 0;
}