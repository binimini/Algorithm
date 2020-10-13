#include <bits/stdc++.h>
using namespace std;
int N, K, d[3] = { 0,1,-1 };
int visited[200001] = { 0 };
queue<int> q;
void BFS() {
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == K)
            return;
        for (int i = 0; i < 3; i++) {
            int nx = x+d[i];
            if (i==0)
                nx = 2 * x;
            if (nx < 0 || nx>200000) continue;
            if (visited[nx]) continue;
            visited[nx] = visited[x] + 1;
            if (nx == K)
                return;
            q.push(nx);
        }
    }
}
int main() {
    cin >> N >> K;
    visited[N] = 1;
    q.push(N);
    BFS();
    cout << visited[K] - 1 << "\n";
    vector<int> v;
    v.push_back(K);
    while (visited[K] - 1 != 0) {
        if (K % 2 == 0&&visited[K/2]==visited[K]-1)
                K = K / 2;
        else if (K + 1 <= 200000 && visited[K + 1] == visited[K] - 1) 
            K = K + 1;
        else if (K - 1 >= 0 && visited[K - 1] == visited[K] - 1) 
            K = K - 1;
        v.push_back(K);
    }
    while (!v.empty()) {
        cout << v.back() << " ";
        v.pop_back();
    }
    return 0;
}