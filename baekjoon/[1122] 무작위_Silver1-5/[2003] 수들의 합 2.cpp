#include <bits/stdc++.h>
using namespace std;
int N, M, arr[10000], result = 0;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    int s = 0, e = 0, sum = arr[0];
    while (1) {
        if (sum > M) {
            sum -= arr[s];
            s++;
        }
        else if (sum < M) {
            if (e < N - 1) {
                e++;
                sum += arr[e];
            }
            else
                break;
        }
        else if (sum == M) {
            result++, sum -= arr[s];
            s++;
        }
    }
    cout << result;
    return 0;
}