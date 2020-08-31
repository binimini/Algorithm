#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, edge[11][11] = { 0 }, arr[11], visited[11] = { 0 }, differ = 1000, s_0 = 0, s_1 = 0;
pair<int, int> people[11];
queue<int> q;
int check() {
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i]) {
            q.push(i);
            while (!q.empty()) {
                i = q.front();
                q.pop();
                for (int j = 0; j < people[i].second; j++) {
                    if (!arr[edge[i][j]]) continue;
                    if (visited[edge[i][j]]) continue;
                    q.push(edge[i][j]);
                }
                visited[i] = 1;
            }
            break;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (arr[i]) {
            if (!visited[i]) return 1000;
            else sum += people[i].first;
        }
        visited[i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        if (!arr[i]) {
            q.push(i);
            while (!q.empty()) {
                i = q.front();
                q.pop();
                for (int j = 0; j < people[i].second; j++) {
                    if (arr[edge[i][j]]) continue;
                    if (visited[edge[i][j]]) continue;
                    q.push(edge[i][j]);
                }
                visited[i] = 1;
            }
            break;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (!arr[i]) {
            if (!visited[i]) return 1000;
            else sum -= people[i].first;
        }
        visited[i] = 0;
    }
    if (sum < 0) sum *= -1;
    return sum;
}
void DFS(int cnt) {
    if (cnt == N + 1) {
        s_0 = 0, s_1 = 0;
        for (int i = 1; i <= N; i++) {
            if (arr[i]) s_1++;
            else s_0++;
            visited[i] = 0;
        }
        if (s_0 < 1 || s_1 < 1) return;
        differ = min(differ, check());
        return;
    }
    for (int i = 0; i < 2; i++) {
        arr[cnt] = i;
        DFS(cnt + 1);
    }
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> people[i].first;
    }
    for (int i = 1; i <= N; i++) {
        cin >> people[i].second;
        for (int j = 0; j < people[i].second; j++) {
            cin >> edge[i][j];
        }
    }
    DFS(1);
    if (differ == 1000)
        cout << -1;
    else cout << differ;
    return 0;
}