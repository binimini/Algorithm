#include <iostream>
using namespace std;
int star(int a, int b, int n, char**& arr) {
    if (n == 3) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (j == 1 && i == 1)
                    arr[a + i][b + j] = ' ';
                else
                    arr[a + i][b + j] = '*';
            }
        }
        return 1;
    }
    for (int i = 0; i < 9; i++) {
        if (i == 4)
            for (int j = 0; j < n / 3; j++) {
                for (int k = 0; k < n / 3; k++)
                    arr[a + j][b + k] = ' ';
            }
        else {
            star(a, b, n / 3, arr);
        }
        if (i == 2 || i == 5)
            a += n / 3, b -= n / 3 * 2;
        else
            b += n / 3;

    }
    return 1;
}
int main() {
    int N;
    cin >> N;
    char** arr = new char* [N + 1];
    for (int i = 0; i < N; i++) {
        arr[i] = new char[N + 1];
    }
    star(0, 0, N, arr);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
    return 0;
}