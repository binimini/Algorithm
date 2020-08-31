#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, check = 0;
    cin >> N;
    if (N < 54) {
        for (int i = 1; i <= N; i++) {
            if (i < 10) {
                if (N == 2 * i) {
                    cout << i << endl;
                    check = 1;
                    break;
                }
            }
            else {
                if (N == i + i % 10 + i / 10) {
                    cout << i << endl;
                    check = 1;
                    break;
                }
            }
        }
    }
    else {
        for (int i = N - 54; i < N; i++) {
            int sum = 0;
            for (int j = 0; j < to_string(i).size(); j++) {
                sum += to_string(i)[j] - '0';
            }
            sum += i;
            if (sum == N) {
                cout << i << endl;
                i = N;
                check = 1;
            }
        }
    }
    if (check == 0) {
        cout << 0 << endl;
    }
    return 0;
}