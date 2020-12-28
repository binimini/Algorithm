#include <bits/stdc++.h>
using namespace std;
int R1, C1, R2, C2, COUNT = 0;
int d[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
int arr[51][6] = { 0 };
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> R1 >> C1 >> R2 >> C2;
    int r = 0, c = 0, cnt = 1, count = 0, di = 0, num = 1;
    int R = max(abs(R1), abs(R2)), C = max(abs(C1), abs(C2));
    if (R1 <= 0 && 0 <= R2 && C1 <= 0 && 0 <= C2) {
        arr[0 - R1][0 - C1] = 1;
        COUNT++;
    }
    int m = 0;
    while (COUNT!=(R2-R1+1)*(C2-C1+1)) {
        count++;
        for (int i = 0; i < cnt; i++) {
            num++;
            r = r + d[di][0];
            c = c + d[di][1];
            if (R1 <= r && r <= R2 && C1 <= c && c <= C2) {
                arr[r - R1][c - C1] = num;
                m = max(m, num);
                COUNT++;
            }
        }
        if (count == 2) {
            count = 0;
            cnt++;
        }
        di = (di + 1) % 4;
    }
    int idx = 0;
    while (m != 0) {
        idx++;
        m /= 10;
    }
    for (int i = 0; i < R2 - R1 + 1; i++) {
        for (int j = 0; j < C2 - C1 + 1; j++) {
            cout.width(idx);
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}