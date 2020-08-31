#include <iostream>
using namespace std;
int cnt = 0, map[10][10], sum = 0;
void check_5(int i, int j) {
    for (int x = i; x < i + 5; x++) {
        for (int y = j; y < j + 5; y++) {
            if (!map[x][y]) return;
        }
    }
    for (int x = i; x < i + 5; x++) {
        for (int y = j; y < j + 5; y++) {
            map[x][y] = 0;
        }
    }
    cnt -= 25;
    sum++;
}
void check_4(int i, int j) {
    for (int x = i; x < i + 4; x++) {
        for (int y = j; y < j + 4; y++) {
            if (!map[x][y]) return;
        }
    }
    for (int x = i; x < i + 4; x++) {
        for (int y = j; y < j + 4; y++) {
            map[x][y] = 0;
        }
    }
    cnt -= 16;
    sum++;
}
void check_3(int i, int j) {
    for (int x = i; x < i + 3; x++) {
        for (int y = j; y < j + 3; y++) {
            if (!map[x][y]) return;
        }
    }
    for (int x = i; x < i + 3; x++) {
        for (int y = j; y < j + 3; y++) {
            map[x][y] = 0;
        }
    }
    cnt -= 9;
    sum++;
}
void check_2(int i, int j) {
    for (int x = i; x < i + 2; x++) {
        for (int y = j; y < j + 2; y++) {
            if (!map[x][y]) return;
        }
    }
    for (int x = i; x < i + 2; x++) {
        for (int y = j; y < j + 2; y++) {
            map[x][y] = 0;
        }
    }
    cnt -= 4;
    sum++;
}
int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> map[i][j];
            if (map[i][j]) cnt++;
        }
    }
    for (int i = 0; i <= 5; i++) {
        for (int j = 0; j <= 5; j++) {
            if (cnt < 25) {
                i = 10, j = 10;
                continue;
            }
            if (map[i][j])
                check_5(i, j);
        }
    }
    for (int i = 0; i <= 6; i++) {
        for (int j = 0; j <= 6; j++) {
            if (cnt < 16) {
                i = 10, j = 10;
                continue;
            }
            if (map[i][j])
                check_4(i, j);
        }
    }
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++) {
            if (cnt < 9) {
                i = 10, j = 10;
                continue;
            }
            if (map[i][j])
                check_3(i, j);
        }
    }
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j <= 8; j++) {
            if (cnt < 4) {
                i = 10, j = 10;
                continue;
            }
            if (map[i][j])
                check_2(i, j);
        }
    }
    if (cnt <= 5)
        cout << sum + cnt;
    else
        cout << -1;
    return 0;
}