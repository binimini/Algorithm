#include <bits/stdc++.h>
using namespace std;
int N, M, arr[10000], sum[10000];
int lb(int key) {
    int s = 0, e = N, m;
    while (e - s > 0) {
        m = (s + e) / 2;
        if (arr[m] < key)
            s = m + 1;
        else
            e = m;
    }
    return e;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        if (i == 0)
            sum[i] = arr[i];
        else
            sum[i] = sum[i - 1] + arr[i];
    }

    cin >> M;
    if (sum[N - 1] <= M)
        cout << arr[N - 1];
    else {
        int result = 0;
        int left = 0, right = arr[N - 1], mid;
        while (right - left >= 0) {
            mid = (left + right) / 2;
            int ss = 0, lo = lb(mid)-1;
            if (lo < 0) {
                ss = 0;
                ss += N * mid;
            }
            else {
                ss = sum[lo];
                ss += (N - lo - 1) * mid;
            }
            if (ss > M)
                right = mid - 1;
            else {
                left = mid + 1;
                result = max(mid, result);
            }
        }
        cout << result;
    }
    return 0;
}