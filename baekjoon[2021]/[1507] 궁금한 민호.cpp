#include <bits/stdc++.h>
using namespace std;
int N, d[20][20] = { 0 }, ori[20][20], INF = 10001;
priority_queue<pair<int,pair<int,int>>> pq;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i!=j)
                d[i][j] = INF;
            cin >> ori[i][j];
            if (ori[i][j])
                pq.push({ -ori[i][j], { i,j } });
        }
    }
    int cost = 0;
    bool impossible = 0, finish = 0;
    while (!pq.empty()) {
        while (!pq.empty()) {
            if (-pq.top().first == d[pq.top().second.first][pq.top().second.second])
                pq.pop();
            else {
                d[pq.top().second.first][pq.top().second.second] = -pq.top().first;
                d[pq.top().second.second][pq.top().second.first] = -pq.top().first;
                cost += -pq.top().first;
                pq.pop();
                break;
            }
        }
        finish = 1;
        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (d[i][j] > d[i][k] + d[k][j])
                        d[i][j] = d[i][k] + d[k][j];
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (ori[i][j] != d[i][j]) {
                    finish = 0;
                    break;
                }
                if (ori[i][j] > d[i][j]) {// check impossible  before finish, finish = 1 so cout cost!! WRONG
                    impossible = 1;
                    break;
                }

            }
        }
        if (finish)
            break;
        if (impossible)
            break;
    }
    if (finish)
        cout << cost;
    else
        cout << -1;
}