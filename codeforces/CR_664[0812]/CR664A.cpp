#include <bits/stdc++.h>
using namespace std;
int T;
int main() {
    int r, g, b, w;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> r >> g >> b >> w;
        int cnt = 0;
        if (r % 2 != 0)
            cnt++;
        if (g % 2 != 0)
            cnt++;
        if (b % 2 != 0)
            cnt++;
        if (w % 2 == 0) {
            if (cnt == 3 || cnt == 0 || cnt == 1)
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
        else {
            if (cnt == 3 || cnt == 0)
                cout << "YES" << "\n";
            else if (cnt == 2 && r > 0 && g > 0 && b > 0)
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
    }
    return 0;
}