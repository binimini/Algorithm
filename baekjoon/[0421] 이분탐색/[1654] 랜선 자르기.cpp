#include <iostream>
#include <algorithm>
using namespace std;
int K, N, arr[10000];
long long int maxi = 0, sum = 0;
long long int lower_bound(long long int start, long long int end) {
    while (end - start > 0) {
        long long int mid = (start + end) / 2, cnt = 0;
        for (int i = 0; i < K; i++) {
            cnt += arr[i] / mid;
        }
        if (cnt >= N) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
    return end;
}
int main() {
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sum = sum / N;
    cout << lower_bound(1, sum + 1) - 1 << "\n";
    return 0;
}