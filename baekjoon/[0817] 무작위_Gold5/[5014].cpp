#include <iostream>
#include <queue>
using namespace std;
int F, S, G, U, D, C = 0;
int visited[1000001] = { 0 };
queue<int> q;
void BFS() {
    while (!q.empty()) {
        int x = q.front();
        if (x == G) {
            cout << visited[x] - 1;
            C = 1;
            return;
        }
        q.pop();
        for (int i = 0; i < 2; i++) {
            int nx;
            if (i == 0)
                nx = x + U;
            else if (i == 1)
                nx = x - D;
            if (nx<1 || nx>F) continue;
            if (visited[nx]) continue;
            visited[nx] = visited[x] + 1;
            q.push(nx);
        }
    }
}
int main() {//스타트링크
    cin >> F >> S >> G >> U >> D;
    q.push(S);
    visited[S] = 1;
    BFS();
    if (!C) cout << "use the stairs";
    return 0;
}