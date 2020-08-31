#include <iostream>
using namespace std;

int main() {
    int x, y, w, h, a, b;
    cin >> x >> y >> w >> h;
    if (x < w - x)
        a = x;
    else
        a = w - x;
    if (y < h - y)
        b = y;
    else
        b = h - y;
    if (a < b)
        cout << a << endl;
    else
        cout << b << endl;
    return 0;
}