#include <iostream>
#include <iomanip>
#include <algorithm>
#include <math.h>
using namespace std;
int lo[3][3];
double length[3], R = 0;
double binary_search(double left, double right) {
    double mid;
    while (right - left >= 0.000001) {
        mid = (right + left) / 2;
        double temp = sqrt(length[1] * length[1] - mid * mid) + sqrt(length[2] * length[2] - mid * mid);
        if (temp > length[0]) {
            left = mid;
        }
        else if (temp == length[0]) {
            return mid;
        }
        else if (temp < length[0]) {
            right = mid;
        }
    }
    return mid;
}
int main() {
    for (int i = 0; i < 3; i++) {
        cin >> lo[i][0] >> lo[i][1] >> lo[i][2];
    }
    for (int i = 0; i < 3; i++) {
        length[i] = sqrt(int(pow(lo[i][0] - lo[(i + 1) % 3][0], 2) + int(pow(lo[i][1] - lo[(i + 1) % 3][1], 2)) + int(pow(lo[i][2] - lo[(i + 1) % 3][2], 2))));
    }
    R = min(length[1], length[2]);
    cout << fixed << setprecision(10);
    cout << binary_search(0, R);

    return 0;
}