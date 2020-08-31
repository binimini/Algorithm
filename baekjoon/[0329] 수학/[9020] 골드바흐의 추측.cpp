#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int check(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return -1;
    }
    return 1;
}
int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int N, num = 0;
        cin >> N;
        for (int j = 2; j < N - 1; j++) {
            if (check(j) == 1)
                if (check(N - j) == 1) {
                    if (num != 0) {
                        if (max(j, N - j) - min(j, N - j) < max(num, N - num) - min(num, N - num))
                            num = j;
                    }
                    else
                        num = min(j, N - j);
                }
        }
        cout << num << " " << N - num << endl;
    }
    return 0;
}