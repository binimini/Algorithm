#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, arr[8], choice[8];
bool visited[8] = { 0 };
void dfs(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < cnt; i++) {
            cout << arr[choice[i]] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visited[i]) continue;
        choice[cnt] = i;
        visited[i] = 1;
        dfs(cnt + 1);
        visited[i] = 0;
    }
}
int main() {
    FASTIO;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    dfs(0);
    return 0;
}