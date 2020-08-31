#include <iostream>
#include <algorithm>
using namespace std;
int M, N;
int main() {
    cin >> M >> N;
    for (int i = min(M, N); i >= 1; i--) {
        if (M % i == 0 && N % i == 0) {
            cout << i << '\n';
            break;
        }
    }
    for (int i = 1; i <= min(M, N); i++) {
        if (max(M, N) * i % min(M, N) == 0) {
            cout << max(M, N) * i << '\n';
            break;
        }
    }
    return 0;
}