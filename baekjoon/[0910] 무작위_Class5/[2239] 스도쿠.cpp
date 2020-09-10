#include <iostream>
using namespace std;
int cnt = 0;
bool CH = 0;
bool ex[3][9][10] = { 0 };//0 블럭 1 세로 2 가로 
int map [9][9] = { 0 };
void DFS(int i, int j) {
    bool flag = 0;
    if (CH == 1)
        return;
    if (i == 9 && j == 0) {
        CH = 1;
        return;
    }

    if (map[i][j]) {
        if (j == 8)
            DFS(i + 1, 0);
        else DFS(i, j + 1);
    }
    else {
        for (int k = 1; k <= 9; k++) {
            if (!ex[0][(i / 3) * 3 + j / 3][k] && !ex[1][i][k] && !ex[2][j][k]) {
                map[i][j] = k;
                ex[0][(i / 3) * 3 + j / 3][k] = 1;
                ex[1][i][k] = 1;
                ex[2][j][k] = 1;
                if (j == 8)
                    DFS(i + 1, 0);
                else DFS(i, j + 1);
                
                if (CH == 1)
                    return;
                map[i][j] = 0;
                ex[0][(i / 3) * 3 + j / 3][k] = 0;
                ex[1][i][k] = 0;
                ex[2][j][k] = 0;
            }

        }
    }
}
int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char temp;
            cin >> temp;
            map[i][j] = temp - '0';
            if (map[i][j] == 0)
                cnt++;
            ex[0][(i/3)*3 + j/3 ][map[i][j]] = 1;
            ex[1][i][map[i][j]] = 1;
            ex[2][j][map[i][j]] = 1;
        }
    }
    DFS(0, 0);
   
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << map[i][j];
        }
        cout << '\n';
    }
    return 0;
}