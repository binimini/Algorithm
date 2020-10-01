#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T,N, first;
int abc[100][3];
bool flag = 0;
vector<int> ans;
void dfs(int i, int v) {
    if (i == N-1) {
        if (first != v) {
            flag = 1;
            return;
        }
        else
            return;
    }
    for (int j = 0; j < 3; j++) {
        if (abc[i + 1][j] != v) {
            ans.push_back(abc[i + 1][j]);
            dfs(i + 1, abc[i + 1][j]);
            if (flag)
                return;
            ans.pop_back();
        }
    }
}
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        flag = 0;
        cin >> N;
        FOR(i, 0, N) {
            cin >> abc[i][0];
        }
        FOR(i, 0, N) {
            cin >> abc[i][1];
        }
        FOR(i, 0, N) {
            cin >> abc[i][2];
        }
        FOR(i, 0, 3) {
            first = abc[0][i];
            ans.clear();
            ans.push_back(first);
            dfs(0, abc[0][i]);
            if (flag)
                break;
        }
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}