#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, M;
int rumor[200001] = { 0 }, visited[200001] = { 0 };
vector<int> child[200001];
queue<int> q;
void BFS() {
    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int i = 0; i < child[x].size(); i++) {
            if (visited[child[x][i]]) continue;

            rumor[child[x][i]]++;

            int stan;
            if (child[child[x][i]].size() % 2 == 0)
                stan = child[child[x][i]].size() / 2;
            else stan = child[child[x][i]].size() / 2 + 1;

            if (rumor[child[x][i]] >= stan) {
                visited[child[x][i]] = visited[x] + 1;
                q.push(child[x][i]);
            }
        }
    }

}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int temp;
    for (int i = 1; i <= N; i++) {
        while (1) {
            cin >> temp;
            if (!temp) break;

            child[i].push_back(temp);
        }
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        visited[temp] = 1;
        q.push(temp);
    }

    BFS();

    for (int i = 1; i <= N; i++) {
        cout << visited[i] - 1 << " ";
    }
    cout << "\n";

    return 0;
}