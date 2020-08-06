#include <bits/stdc++.h>
using namespace std;
int T, N, MAX = 1000000001;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        int a[50] = { 0 };
        int b[50] = { 0 };
        int min_a = MAX, min_b = MAX;
        for (int j = 0; j < N; j++) {
            cin >> a[j];
            min_a = min(a[j], min_a);
        }
        for (int j = 0; j < N; j++) {
            cin >> b[j];
            min_b = min(b[j], min_b);
        }
        long long int sum = 0;
        for (int j = 0; j < N; j++) {
            sum += max(a[j] - min_a, b[j] - min_b);
        }
        cout << sum << '\n';
    }
    return 0;
}