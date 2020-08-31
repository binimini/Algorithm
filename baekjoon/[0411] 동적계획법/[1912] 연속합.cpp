#include <iostream>
#include <algorithm>
using namespace std;
int arr[100001], dp[100001], N, maximum = -1001;
int main() {
    cin.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        maximum = max(dp[i], maximum);
    }
    cout << maximum << '\n';
    return 0;
}