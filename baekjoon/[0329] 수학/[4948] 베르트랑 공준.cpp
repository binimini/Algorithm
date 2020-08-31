#include <iostream>
#include <math.h>
using namespace std;
int check(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return -1;
    }
    return 1;
}
int main() {
    while (1) {
        int N, count = 0;
        cin >> N;
        if (N == 0)
            break;
        for (int i = N + 1; i <= 2 * N; i++) {
            if (check(i) == 1)
                count++;
        }
        cout << count << endl;
    }
    return 0;
}