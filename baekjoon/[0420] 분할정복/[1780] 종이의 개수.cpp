#include <iostream>
using namespace std;
int N, c0 = 0, c1 = 0, c_1 = 0, arr[2187][2187];
void div(int x, int y, int N) {
    if (N == 1) {
        if (arr[x][y] == 0) c0++;
        else if (arr[x][y] == 1) c1++;
        else c_1++;
        return;
    }
    for (int i = x; i < x + N; i++) {
        for (int j = y; j < y + N; j++) {
            if (arr[i][j] != arr[x][y]) {
                div(x, y, N / 3);
                div(x, y + N / 3, N / 3);
                div(x, y + (N / 3) * 2, N / 3);
                div(x + N / 3, y, N / 3);
                div(x + N / 3, y + N / 3, N / 3);
                div(x + N / 3, y + (N / 3) * 2, N / 3);
                div(x + (N / 3) * 2, y, N / 3);
                div(x + (N / 3) * 2, y + N / 3, N / 3);
                div(x + (N / 3) * 2, y + (N / 3) * 2, N / 3);
                return;
            }
        }
    }
    if (arr[x][y] == 0) c0++;
    else if (arr[x][y] == 1) c1++;
    else c_1++;
    return;
}
int main() {
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    div(0, 0, N);
    cout << c_1 << '\n' << c0 << '\n' << c1 << '\n';
    return 0;
}