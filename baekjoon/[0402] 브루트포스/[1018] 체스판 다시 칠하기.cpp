#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int M, N, m = -1;
    cin >> M >> N;
    char** arr = new char* [M + 1];
    for (int i = 0; i < M; i++) {
        arr[i] = new char[N + 1];
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }
    char check1[9][9], check2[9][9];
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            if ((x + y) % 2 == 0) {
                check1[x][y] = 'W', check2[x][y] = 'B';
            }
            else {
                check1[x][y] = 'B', check2[x][y] = 'W';
            }
        }
    }
    for (int i = 0; i < M - 7; i++) {
        for (int j = 0; j < N - 7; j++) {
            int c1 = 0, c2 = 0;
            for (int k = 0; k < 8; k++) {
                for (int l = 0; l < 8; l++) {
                    if (check1[k][l] != arr[i + k][j + l])
                        c1++;
                    if (check2[k][l] != arr[i + k][j + l])
                        c2++;
                }
            }
            if (m < 0)
                m = min(c1, c2);
            else if (m > min(c1, c2))
                m = min(c1, c2);
        }
    }
    cout << m << endl;
    return 0;
}