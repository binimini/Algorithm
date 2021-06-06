#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, arr[300000];
long long int v;
int main() {
    FASTIO;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    v = arr[N - 1];
    for (int i = N - 2; i >= 0; i--) {
        if (v >= arr[i] && v % arr[i] == 0) continue;
        else {
            v /= arr[i];
            v++;
            v = v * arr[i];
        }
    }
    cout << v;
    return 0;
}