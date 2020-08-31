#include <iostream>
#include <algorithm>
using namespace std;
int N, M, result[8], arr[8];
int temp, tempcnt = 0;
int c[10001] = { 0 };//cnt[값] 중복된 수 개수 세기
int visited[10001] = { 0 };//visited[값] 사용한 수 개수 세기
void DFS(int node, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < tempcnt; i++) {
        if (visited[arr[i]] >= c[arr[i]]) continue;
        result[cnt] = arr[i];
        visited[arr[i]]++;
        DFS(i, cnt + 1);
        visited[arr[i]]--;
    }
}
int main() {//N과 M (9)
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    temp = 0, tempcnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        c[temp]++;
        if (c[temp] != 1) continue;
        arr[tempcnt] = temp;
        tempcnt++;
    }
    sort(arr, arr + tempcnt);
    DFS(0, 0);
    return 0;
}