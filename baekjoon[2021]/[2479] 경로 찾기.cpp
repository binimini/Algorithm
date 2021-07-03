#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, K, A, B, dist[1001] = { 0 };
string bit[1001];
vector<int> edge[1001];
queue<int> q;

void bfs() {
    dist[A] = 1;
    q.push(A);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < edge[x].size(); i++) {
            if (dist[edge[x][i]]) continue;
            dist[edge[x][i]] = dist[x] + 1;
            q.push(edge[x][i]);
        }
    }
}
bool calcu(int a, int b) {
    bool flag = 0;
    for (int i = 0; i < K; i++) {
        if (bit[a][i] != bit[b][i]) {
            if (flag)
                return false;
            else
                flag = 1;
        }
    }
    return flag;
}

int main() {
    FASTIO;
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> bit[i];
    }
    cin >> A >> B;

    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if (calcu(i, j)) {
                edge[i].push_back(j);
                edge[j].push_back(i);
            }
        }
    }
    bfs();
    
    if (!dist[B])
        cout << dist[B] - 1;
    else {
        vector<int> ans;
        ans.push_back(B);
        int x = B;
        while (x != A) {
            for (int i = 0; i < edge[x].size(); i++) {
                if (dist[edge[x][i]] == dist[x] - 1) {
                    x = edge[x][i];
                    ans.push_back(x);
                    break;
                }
            }
        }
        while(!ans.empty()) {
            cout << ans.back() << " ";
            ans.pop_back();
        }
    }
    return 0;
}