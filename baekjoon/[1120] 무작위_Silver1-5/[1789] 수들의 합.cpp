#include <bits/stdc++.h>
using namespace std;
long long int S;
int main() {
    cin >> S;
    int N = 1;
    while (S >= N) {
        S -= N;
        N++;
    }
    cout << N - 1;
    return 0;
}