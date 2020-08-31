#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001], DP[1001], N, DP_M = 0;
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
    }
    for (int i = 1; i <= N; i++) {
        int M = 0;
        for (int j = 1; j <= i - 1; j++) {
            if (arr[i] > arr[j]) {
                M = max(M, DP[j]);
            }
        }
        DP[i] = M + 1;
        DP_M = max(DP_M, DP[i]);
    }
    cout << DP_M << '\n';
    return 0;
}