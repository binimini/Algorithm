#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int M, N, d[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
bool flag = 1;
int main() {
    FASTIO;
    cin >> M >> N;
    string comm;
    int temp, x = 0, y = 0, dir = 0;
    for (int i = 0; i < N; i++) {

        cin >> comm >> temp;
        if (comm == "TURN") {
            if (temp == 0)
                dir = (dir + 3) % 4;
            else if (temp == 1)
                dir = (dir + 1) % 4;
        }
        else if (comm == "MOVE") {
            x = x + d[dir][0] * temp;
            y = y + d[dir][1] * temp;
        }
        if (x<0 || x>M || y<0 || y>M) {
            flag = 0;
            break;
        }
    }
    if (flag)
        cout << y << " " << x;
    else
        cout << -1;
    return 0;
}