#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    cin >> N;
    int res = 1;
    for (int i = 2; i <= sqrt(N); i++) {
        if (N % i == 0) {
            res = N / i;
            break;
        }
    }
    cout << N - res;
    return 0;
}