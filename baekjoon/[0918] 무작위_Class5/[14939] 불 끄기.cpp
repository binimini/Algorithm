#include <iostream>
#include <algorithm>
using namespace std;
int cnt = 0, INF = 101, result = INF, adj[5][2] = { {0,0}, {0,-1}, {0,1}, {1,0}, {-1, 0} };
int map[10] = { 0 }, temp_map[10] = { 0 };
int main() {
    char temp;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> temp;
            if (temp == 'O')
                map[i] |= (1 << j);
        }
    }
    for (int i = 0; i <= (1 << 10) - 1; i++) {
        cnt = 0;
        for (int j = 0; j < 10; j++) {
            temp_map[j] = map[j];
        }
        for (int j = 0; j < 10; j++) {//첫 줄 정하기
            if (i & (1 << j)) {
                cnt++;
                for (int k = 0; k < 5; k++) {
                    int nx = 0 + adj[k][0];
                    int ny = j + adj[k][1];
                    if (nx < 0 || nx>9 || ny < 0 || ny>9) continue;
                    temp_map[nx] ^= (1 << ny);
                }
            }
        }

        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (temp_map[i-1]&(1<<j)){
                    cnt++;
                    for (int k = 0; k < 5; k++) {
                        int ni = i + adj[k][0];
                        int nj = j + adj[k][1];
                        if (ni < 0 || ni>9 || nj < 0 || nj>9) continue;
                        temp_map[ni] ^= (1 << nj);
                    }
                }
            }
        }

        bool CH = 1;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (temp_map[i] & (1 << j))
                    CH = 0;
            }
        }
        if (!CH)
            cnt = INF;
        result = min(cnt, result);
    }
    if (result == INF)
        cout << -1;
    else
        cout << result;
    return 0;
}