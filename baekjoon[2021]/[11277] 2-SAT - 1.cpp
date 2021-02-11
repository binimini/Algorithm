#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, temp1, temp2;
bool flag = 0;
pair<int, int> cluster[100];
void dfs(int n, int status) {
    if (flag)
        return;
    if (n == N) {
        for (int i = 0; i < M; i++) {
            if (cluster[i].first < 0)//xi false == status&(1<<i) == 0 // 연산자 우선순위 주의
                (status & 1 << (-cluster[i].first)) == 0 ? temp1 = 1 : temp1 = 0;
            else
                temp1 = status & (1 << (cluster[i].first));
            if (cluster[i].second < 0)
                (status & 1 << (-cluster[i].second)) == 0 ? temp2 = 1 : temp2 = 0;
            else
                temp2 = status & (1 << (cluster[i].second));
            if (!(temp1 || temp2))
                return;
        }
        flag = 1;
        return;
    }
    dfs(n + 1, status | 1 << (n + 1));
    dfs(n + 1, status);
        
}
int main() {
    FASTIO;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> cluster[i].first >> cluster[i].second;
    }
    dfs(0, 0);
    cout << flag;
    return 0;
}