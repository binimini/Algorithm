#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int x1, y1, r1, x2, y2, r2, x, y, d, count = 0;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        d = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        if (r1 == r2 && d == 0) {
            cout << -1 << endl;
        }
        else if (pow(r1 + r2, 2) < d)
            cout << 0 << endl;
        else if (pow(r1 + r2, 2) == d)
            cout << 1 << endl;
        else if (d < pow(r1 + r2, 2) && pow(max(r1, r2) - min(r2, r1), 2) < d)
            cout << 2 << endl;
        else if (pow(max(r2, r1) - min(r1, r2), 2) == d)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}