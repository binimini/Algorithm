#include <bits/stdc++.h>
using namespace std;
int N, arr[4] = { 1,5,10,50 };
bool make[1001] = { 0 };
void solve(int n, int roma, int num) {
    if (n == N) {
        make[num] = 1;
        return;
    }
    if (roma > 3)
        return;
    for (int i = 0; i <= N; i++) {
        if (n + i > N)
            break;
        solve(n + i, roma + 1, num + arr[roma] * i);
    }
}
int main() {
    cin >> N;
    solve(0, 0, 0);
    int res = 0;
    for (int i = 1; i <= 1000; i++) {
        if (make[i])
            res++;
    }
    cout << res;
    return 0;
}