#include <bits/stdc++.h>
using namespace std;
int T,N,M;
int arr[100001];
int tree[200001];
void update(int i, int diff) {
    while (i < 200001) {
        tree[i] += diff;
        i += (i & -i);
    }
}
int sum(int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N >> M;
        for (int i = 1; i <= N + M; i++) {
            tree[i] = 0;
        }
        for (int i = 1; i <= N; i++) {
            arr[i] = M + i;
            update(M + i, 1);
        }
        int temp;
        for (int i = 0; i < M; i++) {
            cin >> temp;
            update(M-i, 1);
            update(arr[temp], -1);
            cout << sum(arr[temp]) - 1 << " ";
            arr[temp] = M-i;
        }
        cout << '\n';
    }
    return 0;
}