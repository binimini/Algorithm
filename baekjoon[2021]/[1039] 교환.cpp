#include <bits/stdc++.h>
using namespace std;
int N, K, res = 0;
bool visited[1000001] = { 0 };
queue<pair<int,int>> q;
void bfs() {
    string temp, ori;
    char swap;
    int prev = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (y > prev) {
            for (int i = 0; i <= min(1000000,(int)pow(10,to_string(N).size()+1)); i++) {
                visited[i] = 0;
            }
        }
        prev = y;
        ori = to_string(x);
        for (int i = 0; i < ori.size(); i++) {
            for (int j = i + 1; j < ori.size(); j++) {
                temp = ori;
                swap = temp[i];
                temp[i] = temp[j];
                temp[j] = swap;
                if (visited[stoi(temp)]) continue;
                if (y + 1 == K)
                    res = max(res, stoi(temp));
                else {
                    visited[stoi(temp)] = 1;
                    q.push(make_pair(stoi(temp), y + 1));
                }
            }
        }
    }
}

int main() {
    cin >> N >> K;
    if (N < 10 || (N < 100 && (N % 10 == 0)))
        cout << -1;
    else {
        q.push(make_pair(N, 0));
        bfs();
        cout << res;
    }
    return 0;
}