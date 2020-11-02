#include <bits/stdc++.h>
using namespace std;
int T,N,M;
int adj[501][501], deg[501], ord[501];
bool flag = 0;
vector<int> ans;
int tpsort() {
    queue<int> q;
    for (int i = 1; i <= N; i++) {
        if (!deg[i])
            q.push(i);
    }
    for (int i = 0; i<N; i++){
        if (q.size() > 1)
            return -1;
        if (q.empty())
            return 0;
        int x = q.front();
        q.pop();
        ans.push_back(x);
        for (int i = 1; i <= N; i++) {
            if (adj[x][i]) {
                deg[i]--;
                if (!deg[i])
                    q.push(i);
            }
        }
    }
    return 1;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int i = 0; i < T; i++) {
        ans.clear();
        cin >> N;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                adj[i][j] = 0;
            }
            deg[i] = 0;
            cin >> ord[i];
        }
        for (int i = 1; i <= N; i++) {
            for (int j = i+1; j <= N; j++) {
                adj[ord[i]][ord[j]] = 1;//ord[i]팀>ord[j]팀
                deg[ord[j]]++;
            }
        }
        cin >> M;
        int a, b;
        for (int i = 0; i < M; i++) {
            cin >> a >> b;
            if (adj[a][b]) {
                adj[a][b] = 0, adj[b][a] = 1;
                deg[b]--, deg[a]++;
            }
            else {
                adj[b][a] = 0, adj[a][b] = 1;
                deg[a]--, deg[b]++;
            }
        }

        int result = tpsort();
        if (result == -1)
            cout << "?\n";
        else if (result == 0)
            cout << "IMPOSSIBLE\n";
        else {
            for (int i = 0; i < N; i++) {
                cout << ans[i] << " ";
            }
            cout << '\n';
        }

    }
    return 0;
}