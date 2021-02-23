#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T, d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int mx = 0, my = 0, Mx = 0, My = 0, x, y, dir;
int main() {
    FASTIO;
    cin >> T;
    string comm;
    for (int t = 0; t < T; t++) {
        mx = 0, my = 0, Mx = 0, My = 0, x = 0, y = 0, dir = 0;
        cin >> comm;
        for (int i = 0; i < comm.size(); i++) {
            if (comm[i] == 'F') {
                x = x + d[dir][0];
                y = y + d[dir][1];
                mx = min(mx, x), my = min(my, y);
                Mx = max(Mx, x), My = max(My, y);
            }
            else if (comm[i] == 'B') {
                x = x + d[(dir + 2) % 4][0];
                y = y + d[(dir + 2) % 4][1];
                mx = min(mx, x), my = min(my, y);
                Mx = max(Mx, x), My = max(My, y);
            }
            else if (comm[i] == 'R')
                dir = (dir + 1) % 4;
            else if (comm[i] == 'L')
                dir = (dir + 3) % 4;
        }
        cout << (Mx - mx) * (My - my)<<"\n";
    }
    return 0;
}