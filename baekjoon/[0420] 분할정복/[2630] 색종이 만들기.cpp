#include <iostream>
using namespace std;
int N, arr[128][128], cnt0 = 0, cnt1 = 0;
void check_and_div(int x, int y, int N) {
    if (N == 1) {
        if (arr[x][y] == 0)
            cnt0++;
        else cnt1++;
        return;
    }
    for (int i = x; i < x + N; i++) {
        for (int j = y; j < y + N; j++) {
            if (arr[i][j] != arr[x][y]) {
                check_and_div(x, y, N / 2);
                check_and_div(x, y + N / 2, N / 2);
                check_and_div(x + N / 2, y, N / 2);
                check_and_div(x + N / 2, y + N / 2, N / 2);
                return;
            }
        }
    }
    if (arr[x][y] == 0)
        cnt0++;
    else cnt1++;
    return;
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    check_and_div(0, 0, N);
    cout << cnt0 << '\n';
    cout << cnt1 << '\n';
    return 0;
}