#include <iostream>
#include <vector>
using namespace std;
int parent[50], cnt = 0;
vector<int> child[50], ignore;
int N;
void delete_node(int i) {
    if (parent[i] != -1) child[parent[i]].pop_back();
    child[i].push_back(-1);
    for (int j = 0; j < child[i].size(); j++) {
        if (child[i][j] == -1) return;
        delete_node(child[i][j]);
    }
}
int main() {
    cin >> N;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        parent[i] = temp;
        if (temp == -1) continue;
        child[temp].push_back(i);

    }
    cin >> temp;
    delete_node(temp);
    for (int i = 0; i < N; i++) {
        if (child[i].empty()) cnt++;
    }
    cout << cnt;
    return 0;
}