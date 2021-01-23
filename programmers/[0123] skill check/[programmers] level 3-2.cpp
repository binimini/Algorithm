#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
void bfs(vector<int> const (&e)[20001], int(&visited)[20001]) {
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < e[node].size(); i++) {
            int next = e[node][i];
            if (visited[next]) continue;
            visited[next] = visited[node] + 1;
            q.push(next);
        }
    }
}
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<int> e[20001];
    for (int i = 0; i < edge.size(); i++) {
        e[edge[i][0]].push_back(edge[i][1]);
        e[edge[i][1]].push_back(edge[i][0]);
    }

    int visited[20001] = { 0 };
    bfs(e, visited);
    int maximum = 0;
    for (int i = 1; i <= n; i++) {
        if (maximum < visited[i]) {
            answer = 1;
            maximum = visited[i];
        }
        else if (maximum == visited[i])
            answer++;
    }
    return answer;
}