#include <iostream>
#include <vector>
using namespace std;
int N, parent[100001], visited[100001] = { 0 };
vector<int> child[100001];
void find_parent(int node) {
    for (int i = 0; i < child[node].size(); i++) {
        if (visited[child[node][i]]) continue;
        else {
            parent[child[node][i]] = node;
            visited[child[node][i]] = 1;
            find_parent(child[node][i]);
        }
    }
}
int main() {
    cin >> N;
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        child[a].push_back(b);
        child[b].push_back(a);
    }
    visited[1] = 1;
    find_parent(1);
    for (int i = 2; i <= N; i++) {
        cout << parent[i] << "\n";
    }
    return 0;
}