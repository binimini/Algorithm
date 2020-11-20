#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int A, P, R = 1;
int main() {
    cin >> A >> P;
    int x = A, nx = 0;
    while (1) {
        if (m.find(x) != m.end())
            break;
        m[x] = R;
        nx = 0;
        while (x != 0) {
            nx += (int)pow(x % 10, P);
            x /= 10;
        }
        x = nx;
        R++;
    }
    cout << m[x] - 1;
    return 0;
}