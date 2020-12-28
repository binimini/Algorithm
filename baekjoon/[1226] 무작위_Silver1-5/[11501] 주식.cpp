#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T, N;
int arr[1000000];
long long int result;
int main() {
    FASTIO;
    cin >> T;
    for (int t = 0; t < T; t++) {
        result = 0;
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        int m = 0;
        for (int i = N - 1; i >= 0; i--) {
            m = max(m, arr[i]);
            if (arr[i] < m)
                result += m - arr[i];
        }
        cout << result<<"\n";
    }
    return 0;
}