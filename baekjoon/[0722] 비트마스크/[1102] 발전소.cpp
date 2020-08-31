#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N, P, c[16][16], dp[1 << 16], MAX = 801;
int find_min(int cnt, int state) {//state일 떄 1111..까지의 비용의 최솟값;
    if (cnt >= P) {
        return 0;
    }
    int& d = dp[state];
    if (d != -1)
        return d;
    d = MAX;
    for (int i = 0; i < N; i++) {
        if (state & (1 << i)) continue;// 켜져있으면 통과
        int cost = MAX;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (!(state & (1 << j))) continue;
            cost = min(cost, c[j][i]);
        }
        d = min(d, find_min(cnt + 1, state | (1 << i)) + cost);//꺼져있는 발전기 하나 키는 경우
    }
    return d;
}
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> c[i][j];
        }
    }
    string s;
    int state = 0, temp = 0;
    cin >> s >> P;
    for (int i = 0; i < N; i++) {
        if (s[i] == 'Y') {
            state |= (1 << i);
            temp++;
        }
    }
    if (temp == 0) {
        if (P == 0)
            cout << 0;
        else if (P > 0)
            cout << -1;
        return 0;
    }
    else if (P <= temp) {
        cout << 0;
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    cout << find_min(temp, state);
    return 0;
}