#include <bits/stdc++.h>
using namespace std;
long long int A, B;
int GCD(long long int a, long long int b) {
    if (a % b == 0)
        return b;
    else
        return GCD(b, a % b);
}
int main() {
    cin >> A >> B;
    int result = GCD(A, B);
    for (int i = 0; i < result; i++) {
        cout << 1;
    }
    cout << '\n';
    return 0;
}