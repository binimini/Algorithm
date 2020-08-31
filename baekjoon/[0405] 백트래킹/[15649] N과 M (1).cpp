#include <iostream>
using namespace std;
bool visited[9] = { 0 };
int arr[9];
int N, M;
void DFS(int cnt) {
    if (cnt == M) {
        for (int i = 1; i <= M; i++) {
            cout << arr[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int j = 1; j <= N; j++) {
        if (visited[j] == true)
            continue;
        visited[j] = true;
        arr[cnt + 1] = j;
        DFS(cnt + 1);
        visited[j] = false;
    }
}
int main() {
    cin >> N >> M;
    DFS(0);
    return 0;
}