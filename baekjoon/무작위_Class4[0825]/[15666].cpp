#include <iostream>
#include <algorithm>
using namespace std;
int N, M, result[8], arr[8];
int temp, tempcnt = 0;
bool visited[10001] = { 0 };
void DFS(int node, int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = node; i < tempcnt; i++) {
        result[cnt] = arr[i];
        DFS(i, cnt + 1);
    }
}
int main() {//N과 M (12)
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    temp = 0, tempcnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (visited[temp]) continue;
        arr[tempcnt] = temp;
        visited[temp] = 1;
        tempcnt++;
    }
    sort(arr, arr + tempcnt);
    DFS(0, 0);
    return 0;
}