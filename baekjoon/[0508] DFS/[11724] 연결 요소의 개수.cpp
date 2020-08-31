#include <iostream>
#include <vector>
using namespace std;
int M, N, cnt = 0, visited_node[1001] = { 0 };
vector<int> arr[1001], visited[1001];
void DFS(int x, int y) {
    visited_node[x] = 1;
    for (int i = 0; i < arr[x].size(); i++) {
        if (visited[x][i] == 1) continue;
        visited[x][i] = 1;
        DFS(arr[x][i], 0);
    }
}
int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(false);
    cin >> M >> N;
    for (int i = 1; i <= N; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        arr[temp1].push_back(temp2);
        arr[temp2].push_back(temp1);
        visited[temp1].push_back(0);
        visited[temp2].push_back(0);
    }
    for (int i = 1; i <= M; i++) {
        if (arr[i].empty()) continue;
        if (visited[i][0] == 1) continue;
        cnt++;
        DFS(i, 0);
    }
    for (int j = 1; j <= M; j++) {
        if (visited_node[j] == 0)
            cnt++;
    }
    cout << cnt << "\n";
    return 0;
}