#include <iostream>
using namespace std;
int N, K, arr[10], cnt;
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int j = N - 1; j >= 0; j--) {//j = N-1
        if (K >= arr[j]) {
            cnt += K / arr[j];
            K = K % arr[j];
        }
    }
    cout << cnt << '\n';
    return 0;
}