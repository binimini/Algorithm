#include <bits/stdc++.h>
using namespace std;
int L, P, V;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int i = 0;
    while (1) {
        i++;
        cin >> L >> P >> V;
        if (!L && !P && !V)
            break;
        int m = V % P;
        if (m > L)
            m = L;
        cout << "Case "<<i<<": "<<(V / P) * L + m << "\n";
    }
    return 0;
}