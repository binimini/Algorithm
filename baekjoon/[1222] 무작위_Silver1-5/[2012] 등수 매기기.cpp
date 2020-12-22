#include <bits/stdc++.h>
using namespace std;
int N, arr[500000];
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += abs(i + 1 - arr[i]);
    }
    cout << sum;
    return 0;
}