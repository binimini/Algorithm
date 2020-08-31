#include <iostream>
#include <algorithm>
using namespace std;
int N, A[1000000], B, C;
long long int cnt = 0;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> B >> C;
    for (int i = 0; i < N; i++) {
        A[i] -= B;
        cnt++;
        if (A[i] > 0) {
            if (A[i] % C != 0) {
                cnt += A[i] / C;
                cnt++;
            }
            else {
                cnt += A[i] / C;
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}