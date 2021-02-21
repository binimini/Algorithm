#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, L, cnt = 0, arr[100000];
int lower_bound(int k) {
    int s = 0, e = N, m;
    while (e - s > 0) {
        m = (s + e) / 2;
        if (arr[m] >= k) 
            e = m;
        else if (arr[m] < k)
            s = m + 1;
    }
    return e;
}
int upper_bound(int k) {
    int s = 0, e = N, m;
    while (e - s > 0) {
        m = (s + e) / 2;
        if (arr[m] > k)
            e = m;
        else if (arr[m] <= k)
            s = m + 1;
    }
    return e;
}
int main() {
    FASTIO;
    cin >> N >> M >> L;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int temp1, temp2, a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        temp1 = a - L + b;
        temp2 = a + L - b;
        if (upper_bound(temp2) - lower_bound(temp1) > 0)
            cnt++;
    }
    cout << cnt;
    return 0;
}