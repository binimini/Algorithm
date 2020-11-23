#include <bits/stdc++.h>
using namespace std;
int N, C, arr[200000], result = 0;
int install(int dist) {
    int cnt = 1;
    int cur = arr[0];
    for (int i = 0; i < N; i++) {
        if (arr[i] - cur >= dist) {
            cur = arr[i];
            cnt++;
        }
    }
    return cnt;
}
void bs() {
    int s = 1, e = arr[N - 1] - arr[0], m;
    while (e - s >= 0) {
        m = (s + e) / 2;
        if (install(m)>=C) {
            result = max(result, m);
            s = m + 1;
        }
        else 
            e = m - 1;
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> C;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    bs();
    cout << result;
    return 0;
}