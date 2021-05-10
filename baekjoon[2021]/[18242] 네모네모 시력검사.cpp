#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, x, y,di = 0, d[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
bool arr[101][101], flag = 0;
int check(int i, int j, int dir) {
    int cnt = 0, ni, nj, nni, nnj;
    while (1) {
        ni = i + d[dir][0];
        nj = j + d[dir][1];
        nni = i + d[dir][0]*2;
        nnj = j + d[dir][1]*2;
        if (arr[ni][nj] == 1) {
            cnt ++;
            i = ni, j = nj;
        }
        else if (arr[nni][nnj] == 1) {
            flag = 1;
            return 0 ;
        }
        else 
            return cnt;
    }
}
int main() {
    FASTIO;
    cin >> N >> M;
    char temp;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> temp;
            if (temp == '#')
                arr[i][j] = 1;
            else
                arr[i][j] = 0;
        }
    }
    int n = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j]&&!flag) {
                x = i, y = j;
                for (int k = 0; k < 4; k++) {
                    n = check(x, y, di);
                    if (flag) {
                        if (k == 0)
                            cout << "UP\n";
                        else if (k == 1)
                            cout << "RIGHT\n";
                        else if (k == 2)
                            cout << "DOWN\n";
                        else if (k == 3)
                            cout << "LEFT\n";
                        break;
                    }
                    else {
                        x += d[di][0] * n;
                        y += d[di][1] * n;
                        di++;
                    }
                }
            }
        }
    }
    return 0;
}