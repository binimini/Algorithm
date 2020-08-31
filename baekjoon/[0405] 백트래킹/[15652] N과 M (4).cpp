#include <iostream>
using namespace std;
int N, M;
int arr[9];
void DFS(int cnt, int x) {
    if (cnt == M) {
        for (int i = 1; i <= M; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int j = x; j <= N; j++) {
        arr[cnt + 1] = j;
        DFS(cnt + 1, j);
    }
}
int main() {
    cin >> N >> M;
    DFS(0, 1);
    return 0;
}