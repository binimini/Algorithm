#include <iostream>
using namespace std;
int N, M;
int arr[8];
void DFS(int cnt) {
    if (cnt == M) {
        for (int i = 1; i <= M; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int j = 1; j <= N; j++) {
        arr[cnt + 1] = j;
        DFS(cnt + 1);
    }
}
int main() {
    cin >> N >> M;
    DFS(0);
}