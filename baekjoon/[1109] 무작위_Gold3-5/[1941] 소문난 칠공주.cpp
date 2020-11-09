#include <bits/stdc++.h>
using namespace std;
int arr[7], result = 0, d[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
bool mapp[5][5] = { 0 }, s[5][5] = { 0 };
queue<pair<int, int>> q;
bool check() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            s[i][j] = 0;
        }
    }
    int start, tcnt=0, scnt = 0;
    for (int i = 0; i < 7; i++) {
        s[arr[i] / 5][arr[i] % 5] = 1;
        start = arr[i];
    }
    if (mapp[start / 5][start % 5]) {
        scnt++;
    }
    s[start / 5][start % 5] = 0;
    tcnt++;
    q.push(make_pair(start / 5, start % 5));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + d[i][0];
            int ny = y + d[i][1];
            if (nx < 0 || nx>4 || ny < 0 || ny>4) continue;
            if (!s[nx][ny]) continue;
            s[nx][ny] = 0;
            tcnt++;
            if (mapp[nx][ny])
                scnt++;
            q.push(make_pair(nx, ny));
        }
    }
    return ((tcnt == 7) && (scnt >= 4));
}
void dfs(int node, int cnt) {
    if (cnt == 7) {
        if (check())
            result++;
        return;
    }
    for (int i = node; i < 25; i++) {
        arr[cnt] = i;
        dfs(i+1, cnt + 1);
    }
}

int main() {
    char temp;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> temp;
            if (temp == 'S')
                mapp[i][j] = 1;
        }
    }
    dfs(0, 0);
    cout << result;
    return 0;
}