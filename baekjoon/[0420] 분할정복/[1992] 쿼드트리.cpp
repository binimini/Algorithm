#include <iostream>
using namespace std;
int N, arr[64][64];
void div(int x, int y, int N) {
    if (N == 1) {
        cout << arr[x][y];
        return;
    }
    for (int i = x; i < x + N; i++) {
        for (int j = y; j < y + N; j++) {
            if (arr[i][j] != arr[x][y]) {
                cout << "(";
                div(x, y, N / 2);
                div(x, y + N / 2, N / 2);
                div(x + N / 2, y, N / 2);
                div(x + N / 2, y + N / 2, N / 2);
                cout << ")";
                return;
            }

        }
    }
    cout << arr[x][y];
    return;
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            char temp;
            cin >> temp;
            arr[i][j] = temp - '0';
        }
    }
    div(0, 0, N);
    return 0;
}