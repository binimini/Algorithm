#include <iostream>
using namespace std;
int N, M;
char arr[101][101];
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    for (int j = M - 1; j >= 0; j--) {
        for (int i = 0; i < N; i++) {
            if (arr[i][j] == 46)
                cout << '.';
            else if (arr[i][j] == 79)
                cout << 'O';
            else if (arr[i][j] == 45)
                cout << '|';
            else if (arr[i][j] == 124)
                cout << '-';
            else if (arr[i][j] == 47)
                cout << '\\';
            else if (arr[i][j] == 92)
                cout << '/';
            else if (arr[i][j] == 94)
                cout << '<';
            else if (arr[i][j] == 60)
                cout << 'v';
            else if (arr[i][j] == 118)
                cout << '>';
            else if (arr[i][j] == 62)
                cout << '^';
        }
        cout << '\n';
    }
    return 0;
}