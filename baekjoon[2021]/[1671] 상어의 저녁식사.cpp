#include <bits/stdc++.h>
using namespace std;
int N;
int arr[51][3];
bool visited[51] = { 0 };
int eatenby[51] = { 0 };
vector<int> can_eat[51];
bool dfs(int me) {
    if (visited[me]) return 0;
    visited[me] = 1;
    for (int i = 0; i < can_eat[me].size(); i++) {
        int target = can_eat[me][i];
        //if (eatenby[me] == target) continue;
        if (eatenby[target] == 0 || dfs(eatenby[target])) {
            eatenby[target] = me;
            return 1;
        }
    }
    return 0;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            if (arr[i][0] >= arr[j][0] && arr[i][1] >= arr[j][1] && arr[i][2] >= arr[j][2]) {
                if (arr[i][0] == arr[j][0] && arr[i][1] == arr[j][1] && arr[i][2] == arr[j][2]) {
                    if (i>j)//같은 경우 인덱스 큰쪽만 먹을 수 있다
                        can_eat[i].push_back(j);
                }
                else
                    can_eat[i].push_back(j);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 1; k <= N; k++)
                visited[k] = 0;
            if (dfs(i))
                res++;
        }
    }
    cout << N-res;
    return 0;
}