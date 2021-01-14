#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int A, B, C;
ll pow(int a, int b, int c) {
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    ll m;
    if (b % 2 == 0) {
        m = pow(a, b / 2, c);
        return (m * m % c);
    }
    else if (b % 2 != 0) {
        m = pow(a, (b - 1) / 2, c);
        m = (m * m )% c;
        return (a * m) % c;
    }
}
int main() {
    cin >> A >> B >> C;
    cout << (pow(A, B, C))%C;
    return 0;
}