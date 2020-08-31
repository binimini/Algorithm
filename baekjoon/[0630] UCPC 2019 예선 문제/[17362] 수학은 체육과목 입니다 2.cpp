#include <iostream>
using namespace std;
int N;
int main() {
    cin >> N;
    if (N == 1)
        cout << 1;
    else {
        N -= 2;
        if ((N / 4) % 2 == 0) {
            cout << N % 4 + 2;
        }
        else if ((N / 4) % 2 != 0) {
            cout << 4 - (N % 4);
        }
    }
    return 0;
}