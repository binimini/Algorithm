#include <iostream>
using namespace std;
int main() {
    int X, sum = 2, x = 1, y = 1;
    cin >> X;
    for (int i = 0; i < X - 1; i++) {
        if (sum % 2 == 0) {
            if (x == 1) {
                sum++;
                x = 1; y = sum - 1;
            }
            else
                x--, y++;
        }
        else {
            if (y == 1) {
                sum++;
                y = 1; x = sum - 1;
            }
            else
                y--, x++;
        }
    }
    cout << x << '/' << y << endl;
}