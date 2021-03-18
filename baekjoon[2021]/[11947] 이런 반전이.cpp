#include <bits/stdc++.h>
using namespace std;
long long int temp;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T, N;
int main() {
    FASTIO;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        int cnt = 0, copyN = N;
        while (copyN > 0) {
            copyN /= 10;
            cnt++;
        }
        long long int middle = pow(10, cnt) / 2 - 1, nine = 0, temp;
        cnt--;
        while (cnt>=0) {
            temp = pow(10, cnt);
            temp *= 9;
            nine += temp;
            cnt--;
        }
        if (N >= middle)
            cout << middle * (nine - middle)<<"\n";
        else
            cout << N * (nine - N)<<"\n";
    }
    return 0;
}