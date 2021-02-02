#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
int N, M, res = 0, B[201];
vector<int> edge[201];
bool visited[201] = { 0 };
bool dfs(int node) {//이분 매칭 
    if (visited[node]) return 0;//이미 방문한 정점일경우 false
    visited[node] = 1;
    for (int i = 0; i < edge[node].size(); i++) {
        int b = edge[node][i];
        if (B[b] == -1 || dfs(B[b])) {//B 그룹에서 매칭 안되있거나 해당 b 매칭 a (B[b])가 다른 점 매칭 가능 시
            B[b] = node;
            return 1;
        }
    }
    return 0;
}
void match() {
    for (int i = 1; i <= N; i++) {
        for (int i = 1; i <= N; i++)//정점 별 매칭 가능 여부 확인시마다 visited 초기화해야한다. 
            //visited 정점 매칭 내에서의 방문여부
            visited[i] = 0;
        if (dfs(i)) res++;//이미 매칭한 것 기반으로 새로운 매칭 가능하면 매칭 수 늘린다.
    }
}
int main() {
    FASTIO;
    cin >> N >> M;
    memset(B, -1, sizeof(B));
    int size, temp;
    for (int i = 1; i <= N; i++) {
        cin >> size;
        for (int j = 0; j < size; j++) {
            cin >> temp;
            edge[i].push_back(temp);
        }
    }
    match();
    cout << res;
    return 0;
}