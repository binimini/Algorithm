#include <iostream>
using namespace std;

int main() {
    int N, check = 0;
    cin >> N;
    if (N % 5 == 0)
        cout << N / 5 << endl;
    else {
        for (int i = N / 5; i >= 0; i--) {
            if ((N - 5 * i) % 3 == 0) {
                cout << (N - 5 * i) / 3 + i << endl;
                check = 1;
                break;
            }
        }
        if (check == 0) {
            cout << -1 << endl;
        }
    }
    return 0;
}