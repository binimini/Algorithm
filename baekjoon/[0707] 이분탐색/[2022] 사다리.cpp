#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
double x, y, c;
double binary_search(double left, double right) {
    double mid;
    while (right - left >= 0) {
        mid = (right + left) / 2;
        double temp1, temp2;
        temp1 = sqrt(x * x - mid * mid);
        temp2 = sqrt(y * y - mid * mid);
        if (temp1 * temp2 / (temp1 + temp2) > c) {
            if (left == mid) {
                return mid;
            }
            left = mid;
        }
        else if (temp1 * temp2 / (temp1 + temp2) == c) {
            return mid;
        }
        else if (temp1 * temp2 / (temp1 + temp2) < c) {
            if (right == mid) {
                return mid;
            }
            right = mid;
        }
    }
}
int main() {
    cin >> x >> y >> c;
    cout << double(round(binary_search(0, min(x, y)) * 1000)) / 1000;
    return 0;
}