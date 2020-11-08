#include <bits/stdc++.h>
using namespace std;
int T, N, A, B;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> A >> B;
        int k;
        while (A!= 0) {
            if (A != 1)
                k = B / A + 1;
            else
                k = B / A;
  
            A *= k;
            A -= B;
            B *= k;
            for (int i = A; i >= 2; i--) {
                if (A % i == 0 && B % i == 0)
                    A /= i, B /= i;
            }
        }
        cout << k << '\n';
    }
    return 0;
}