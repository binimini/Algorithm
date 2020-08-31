#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001][3];
int cost[1001][3];
int main() {
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    arr[1][0] = cost[1][0], arr[1][1] = cost[1][1], arr[1][2] = cost[1][2];
    for (int i = 2; i <= N; i++) {
        arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + cost[i][0];
        arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + cost[i][1];
        arr[i][2] = min(arr[i - 1][0], arr[i - 1][1]) + cost[i][2];
    }
    cout << min(min(arr[N][0], arr[N][1]), arr[N][2]) << '\n';
    return 0;
}