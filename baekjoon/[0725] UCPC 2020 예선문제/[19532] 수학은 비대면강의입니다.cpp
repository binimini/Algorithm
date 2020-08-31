#include <iostream>
using namespace std;

int main() {
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    int x = b * f - e * c;
    int y = c * d - a * f;
    int z = b * d - a * e;
    x = x / z;
    y = y / z;
    cout << x << " " << y;
    return 0;
}