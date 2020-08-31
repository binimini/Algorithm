#include <iostream>
#include <algorithm>
using namespace std;
int T, N, cnt5, five_div;
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> N;
        cnt5 = 0, five_div = 5;
        while (five_div <= N) {
            cnt5 += N / five_div;
            five_div *= 5;
        }
        cout << cnt5 << "\n";
    }
}