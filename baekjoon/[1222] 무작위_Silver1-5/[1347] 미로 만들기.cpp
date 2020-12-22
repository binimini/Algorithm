#include <bits/stdc++.h>
using namespace std;
int N, mx = 50, Mx = 50, my = 50, My = 50;
int d[4][2] = { {1,0},{0,-1},{-1,0},{0,1} };
string comm;
bool mapp[101][101] = { 0 };

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N;
    cin >> comm;
    int x = 50, y = 50, di = 0;
    mapp[x][y] = 1;
    for (int i = 0; i < N; i++) {
        if (comm[i] == 'L') {
            if (di == 0)
                di = 3;
            else
                di -= 1;
        }
        else if (comm[i] == 'R')
            di = (di + 1) % 4;
        else if (comm[i] == 'F') {
            x = x + d[di][0];
            y = y + d[di][1];
        }
        mapp[x][y] = 1;
        mx = min(mx, x);
        my = min(my, y);
        Mx = max(Mx, x);
        My = max(My, y);
    }
    for (int i = mx; i <= Mx; i++) {
        for (int j = my; j <= My; j++) {
            if (mapp[i][j])
                cout << ".";
            else
                cout << "#";
        }
        cout << '\n';
    }
    return 0;
}