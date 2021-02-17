#include <bits/stdc++.h>
using namespace std;
int N, res = 0;
int solve(int n) {
    int s = 1, e = 1, sum = 0;
    while (e<=N+1) {
        if (sum >= N)
            sum -= s++;
        else if (sum < N) {
            if (e == N + 1)
                break;
            else
                sum += e++;
        }
        if (sum == N)
            res++;
    }
    return res;
}
int main() {
    cin >> N;
    cout << solve(N);
    return 0;
}