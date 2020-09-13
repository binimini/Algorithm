#include <bits/stdc++.h>
using namespace std;
int T, N;
string day[6] = { "Mon", "Tue", "Wed", "Thu", "Fri" };
int main() {
    cin >> T >> N;
    int sum = 0;
    int h1,h2;
    string d1, d2;
    int d11, d22;
    for (int i = 0; i < N;  i++) {
        cin >> d1 >> h1 >> d2 >> h2;
        for (int i = 0; i < 5; i++) {
            if (day[i] == d1)
                d11 = i;
            if (day[i] == d2)
                d22 = i;
        }
        sum += 24 * (d22 - d11 - 1) + 24 - h1 + h2;

    }
    if (sum >= T)
        cout << 0 << "\n";
    else if (T - sum > 48)
        cout << -1 << '\n';
    else cout << T - sum << "\n";
    return 0;
}