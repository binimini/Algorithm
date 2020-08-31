#include <iostream>
#include <queue>
using namespace std;
int N, K, L, arr[100][100] = { 0 }, direc[10001] = { 0 }, d[4][2] = { {0,1},{1,0},{0,-1},{-1,0} }, time = -1, direction = 0, tail = 0;
queue<pair<int, int>> q;
pair<int, int> snake[10001];
int GAME_START() {
    while (1) {
        time++;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        if (direc[time]) {
            if (direc[time] == 1 && direction == 3)
                direction = 0;
            else if (direc[time] == -1 && direction == 0)
                direction = 3;
            else
                direction += direc[time];
        }
        int nx = x + d[direction][0], ny = y + d[direction][1];

        if (nx<0 || ny<0 || nx>N - 1 || ny>N - 1)
            return time + 1;
        if (arr[nx][ny] == 1)
            return time + 1;

        if (!arr[nx][ny]) {
            arr[snake[tail].first][snake[tail].second] = 0;
            tail++;
        }
        arr[nx][ny] = 1;
        snake[time + 1].first = nx;
        snake[time + 1].second = ny;
        q.push(make_pair(nx, ny));
    }
}
int main() {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        arr[x - 1][y - 1] = -1;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        int t;
        char comm;
        cin >> t >> comm;
        if (comm == 'L')
            direc[t] = -1;
        else
            direc[t] = 1;
    }
    q.push(make_pair(0, 0));
    arr[0][0] = 1;
    snake[0].first = 0; snake[0].second = 0;
    cout << GAME_START();
    return 0;
}