#include <bits/stdc++.h>
using namespace std;
int N, arr[20];
bool is[2000001] = { 0 };
void solve(int n, int sum) {
    if (n == N) {
        is[sum] = 1;
        return;
    }
    
    solve(n + 1, sum + arr[n]);
    solve(n + 1, sum);
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    solve(0,0);
    for (int i = 1; i <= 2000000; i++) {
        if (!is[i]) {
            cout << i << "\n";
            break;
        }
    }
    return 0;
}