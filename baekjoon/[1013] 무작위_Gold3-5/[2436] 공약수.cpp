#include <bits/stdc++.h>
using namespace std;
int A, B;
int main() {
    cin >> A >> B;
    int N = B / A;
    int v = 200000001, x, y;
    for (int i = 1; i <= (int)sqrt(N); i++) {
        if (N % i != 0) continue;
        int a = max(N / i,i);
        int b = min(N / i, i);
        int c;
        while (b) {
            c = a % b;
            a = b;
            b = c;
        }
        if (a != 1) continue;//a b 서로소여야함 아니면 공통 수 lcm = K*gcd*a*b로 주어진 수가 lcm gcd 성립되지않음
        if ((N / i) * A + i * A < v) {
            v = (N / i) * A + i * A;
            x = min((N / i) * A, i * A);
            y = max((N / i) * A, i * A);
        }
    }
    cout << x << " " << y << "\n";
    return 0;
}