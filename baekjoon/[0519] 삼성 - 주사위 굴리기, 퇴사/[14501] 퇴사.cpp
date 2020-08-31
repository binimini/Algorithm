#include <iostream>
#include <algorithm>
using namespace std;
int N, T[16], P[16] = { 0 }, arr[15] = { 0 }, pay = 0;
void DFS(int node, int cnt, int t) {
    for (int i = node; i <= N; i++) {
        if (i + T[i] - 1 > N) continue;
        arr[cnt] = i;
        DFS(i + T[i], cnt + 1, t + T[i]);
    }
    if (t <= N) {
        int sum = 0;
        for (int i = 0; i < cnt; i++) {
            sum += P[arr[i]];
        }
        pay = max(sum, pay);
    }
    return;
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }
    DFS(1, 0, 0);
    cout << pay << "\n";
}