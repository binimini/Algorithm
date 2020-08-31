#include <iostream>
#include <queue>
using namespace std;
int N, K, visited[100001] = { 0 }, cnt = 0;
queue<int> q;
void BFS() {
    while (1) {
        int x = q.front();
        if (x == K) {
            cnt = visited[x] - 1;
            break;
        }
        q.pop();
        for (int i = 0; i < 3; i++) {
            int nx;
            if (i == 0)
                nx = x * 2;
            else if (i == 1)
                nx = x + 1;
            else
                nx = x - 1;
            if (nx < 0 || nx>100000) continue;
            if (visited[nx]) continue;
            visited[nx] = visited[x] + 1;
            q.push(nx);
        }
    }
}
int main() {
    cin >> N >> K;
    visited[N] = 1;
    q.push(N);
    BFS();
    cout << cnt << '\n';
    return 0;
}