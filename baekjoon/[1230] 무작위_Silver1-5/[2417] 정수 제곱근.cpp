#include <bits/stdc++.h>
using namespace std;
unsigned long long int N;
int main() {
    unsigned long long int s = 0, e = pow(2, 32);
    e++;
    cin >> N;
    while (s < e) {//long long int <2^63 unsigned long long int <2^64
        unsigned long long int m = (s + e) / 2;
        if (m * m >= N)
            e = m;
        else 
            s = m + 1;
    }
    cout << e;
    return 0;
}