#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int R, C, K, rr,rc;
int d[4], direc[5][2] = { {0,0},{-1,0},{1,0},{0,-1},{0,1} };
bool mapp[1000][1000] = { 0 };
void move() {
    int check = 0;
    int rd = 0;
    mapp[rr][rc] = 1;
    while (check<=4) {
        int nr = rr + direc[d[rd]][0];
        int nc = rc + direc[d[rd]][1];
        if (nr<0 || nr>R - 1 || nc<0 || nc>C - 1) {
            check++;
            rd = (rd + 1) % 4;
            continue;
        }
        if (mapp[nr][nc]) {
            check++;
            rd = (rd + 1) % 4;
            continue;
        }
        check = 0;
        while (!(mapp[nr][nc] || nr<0 || nr>R - 1 || nc<0 || nc>C - 1)) {
            rr = nr, rc = nc;
            mapp[rr][rc] = 1;
            nr = rr + direc[d[rd]][0];
            nc = rc + direc[d[rd]][1];
        }
        rd = (rd + 1) % 4;
    }
}
int main() {
    FASTIO;
    cin >> R >> C >> K;
    int r, c;
    for (int i = 0; i < K; i++) {
        cin >> r >> c;
        mapp[r][c] = 1;
    }
    cin >> rr >> rc;
    cin >> d[0] >> d[1] >> d[2] >> d[3];
    move();
    cout << rr << " " << rc;
    return 0;
}