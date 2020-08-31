#include <iostream>
#include <math.h>
using namespace std;
int gear[5][8], attach[5] = { -1,0,0,0,-1 }, N, sum;
void rotation(int N, int direct) {
    int temp[10] = { 0 };
    if (direct == 1)
        temp[1] = gear[N][7];
    else
        temp[8] = gear[N][0];
    for (int i = 0; i < 8; i++) {
        temp[i + 1 + direct] = gear[N][i];
    }
    for (int i = 1; i <= 8; i++) {
        gear[N][i - 1] = temp[i];
    }
}
void attach_check() {
    if (gear[1][2] != gear[2][6])
        attach[1] = 1;
    else if (gear[1][2] == gear[2][6])
        attach[1] = 0;
    if (gear[2][2] != gear[3][6])
        attach[2] = 1;
    else if (gear[2][2] == gear[3][6])
        attach[2] = 0;
    if (gear[3][2] != gear[4][6])
        attach[3] = 1;
    else if (gear[3][2] == gear[4][6])
        attach[3] = 0;
}
void check_rotate(int K, int direct, int crease) {
    if (K > 4 || K < 1)
        return;
    if (crease == 0)
        rotation(K, direct);
    if (crease == -1 || crease == 0) {
        if (attach[K - 1] == 1) {
            if (direct == 1) {
                rotation(K - 1, -1);
                check_rotate(K - 1, -1, -1);
            }
            else {
                rotation(K - 1, 1);
                check_rotate(K - 1, 1, -1);
            }
        }
    }
    if (crease == 1 || crease == 0) {
        if (attach[K] == 1) {
            if (direct == 1) {
                rotation(K + 1, -1);
                check_rotate(K + 1, -1, 1);
            }
            else {
                rotation(K + 1, 1);
                check_rotate(K + 1, 1, 1);
            }
        }
    }
}
int main() {
    for (int i = 1; i <= 4; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            gear[i][j] = s[j] - '0';
        }
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        int K, direct;
        cin >> K >> direct;
        attach_check();
        check_rotate(K, direct, 0);
    }
    for (int i = 1; i <= 4; i++) {
        if (gear[i][0] == 1)
            sum += int(pow(2, i - 1));
    }
    cout << sum << '\n';
    return 0;
}