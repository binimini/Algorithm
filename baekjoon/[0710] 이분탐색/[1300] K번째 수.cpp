#include <iostream>
#include <algorithm>
using namespace std;
int N, K, R = 1000000001;
int binary_search(int left, int right) {
    int mid;
    while (right - left >= 0) {
        mid = (right + left) / 2;
        long long int cnt = 0;
        for (int i = 1; i <= N; i++) {
            cnt += min(mid / i, N);
        }
        if (cnt >= K) {
            R = min(R, mid);
            right = mid - 1;
        }
        else if (cnt < K)
            left = mid + 1;
    }
    return R;
}
int main() {
    cin >> N >> K;
    cout << binary_search(1, K);
    return 0;
}