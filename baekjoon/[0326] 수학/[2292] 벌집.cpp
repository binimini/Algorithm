#include <iostream>
using namespace std;

int main() {
    int N, i = 1;
    cin >> N;
    N = N - 1;
    while (N > 0) {
        N -= 6 * i;
        i++;
    }
    cout << i << endl;
    return 0;
}