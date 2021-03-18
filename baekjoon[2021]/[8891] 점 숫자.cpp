#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T, A, B;
pair<int,int> toLo[10001];
int toNum[301][301];
int main() {
    FASTIO;
    cin >> T;
    int cnt = 1;
    int x = 1, y = 1, r = 1;
    while (1) {
        if (cnt<=10000)
            toLo[cnt].first = x, toLo[cnt].second = y;
        toNum[x][y] = cnt;
        if (x == 1 && y == 300)
            break;
        cnt++;
        if (x == 1)
            x = ++r, y = 1;
        else
            x--, y++;
    }
    int ax, ay, bx, by;
    for (int t = 0; t < T; t++) {
        cin >> A >> B;
        ax = toLo[A].first, ay = toLo[A].second;
        bx = toLo[B].first, by = toLo[B].second;
        cout << toNum[ax + bx][ay + by]<<"\n";
    }
    return 0;
}