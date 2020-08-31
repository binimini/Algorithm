#include <iostream>
using namespace std;
int N, X, Y, cnt = 1;
int main() {
    cin >> N >> X >> Y;
    while (1) {
        if ((X - 1) / 2 == (Y - 1) / 2) {
            cout << cnt << "\n";
            break;
        }
        else {
            if (X % 2 == 0)
                X = X / 2;
            else
                X = (X - 1) / 2 + 1;
            if (Y % 2 == 0)
                Y = Y / 2;
            else
                Y = (Y - 1) / 2 + 1;
            cnt++;
        }

    }
    return 0;
}