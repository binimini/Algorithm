#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, arr[8], choice[8];
bool visited[8] = { 0 };
void dfs(int node, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < cnt; i++) {
            cout << arr[choice[i]] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = node; i < N; i++) {
        choice[cnt] = i;
        dfs(i, cnt + 1);
    }
}
int main() {
    FASTIO;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    dfs(0,0);
    return 0;
}