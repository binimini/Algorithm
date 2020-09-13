#include <bits/stdc++.h>
using namespace std;
int N, Q;
int arr[250001];
int lower_bound(int key) {
    int s = 0, e = N + 1;
    int m;
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
    cout.tie(0);
    cin >> N >> Q;
    for (int i = N; i >=1; i--) {
        cin >> arr[i];
    }
    int x, y;
    for (int i = 0; i < Q; i++) {
        cin >> x >> y;
        int temp = N - lower_bound(x)-y +1 + arr[N-y+1] - x +1;
        if (temp <= 0)
            cout << 0 << "\n";
        else cout << temp << "\n";
    }
}