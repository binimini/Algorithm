#include <iostream>
int arr[6], visited[13] = { 0 }, num[13], K;
using namespace std;
void DFS(int node, int cnt) {
    if (cnt == 6) {
        for (int i = 0; i < 6; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = node; i < K; i++) {
        if (visited[i] == 1) continue;
        visited[i] = 1;
        arr[cnt] = num[i];
        DFS(i, cnt + 1);
        visited[i] = 0;
    }
}
int main() {
    int c = 0;
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    while (1) {
        cin >> K;
        if (K == 0)
            break;
        else if (c != 0)
            cout << "\n";
        for (int i = 0; i < K; i++) {
            cin >> num[i];
        }
        DFS(0, 0);
        c = 1;
    }
    return 0;
}