#include <iostream>
using namespace std;
int N, M;
int arr[9];
bool visited[9] = { 0 };
void DFS(int cnt, int x) {
    if (cnt == M) {
        for (int i = 1; i <= M; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
    }
    for (int j = x + 1; j <= N; j++) {
        if (visited[j] == true)
            continue;
        visited[j] = true;
        arr[cnt + 1] = j;
        DFS(cnt + 1, j);
        visited[j] = false;
    }
}
int main() {
    cin >> N >> M;
    DFS(0, 0);
    return 0;
}