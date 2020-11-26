#include <bits/stdc++.h>
using namespace std;
int N, arr[100];
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int cnt = 0;
    for (int i = N-1; i >=0; i--) {
        if (i != N - 1) {
            if (arr[i] >= arr[i + 1]) {
                cnt += arr[i] - arr[i + 1] + 1;
                arr[i] = arr[i + 1] - 1;
            }
        }
    }
    cout << cnt;
    return 0;
}