#include <iostream>
#include <queue>
using namespace std;
int xy[2][2];
int N;
long double ccw(long long int x1, long long int y1,long long int x2, long long int y2,long long int x3, long long int y3) {
    long long int temp = ((x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3));
    double t = temp / 2.0;
    return t;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int x, y;
    cin >> x >> y;
    cin >> xy[0][0] >> xy[0][1];
    long double area = 0;
    for (int i = 0; i < N-2; i++) {
        int t = i % 2;
        cin >> xy[1 - t][0] >> xy[1 - t][1];
        area += ccw(x, y, xy[t][0], xy[t][1], xy[1 - t][0], xy[1 - t][1]);
    }
    if (area < 0)
        area *= -1;
    cout << fixed;
    cout.precision(1);
    cout << area << "\n";
    return 0;
}