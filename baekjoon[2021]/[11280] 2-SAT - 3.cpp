#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
int N, M, visitcount = 1;
stack<int> st;
vector<int> edge[20001];
int discover[20001] = { 0 }, scc[20001] = { 0 };
int dfs(int node) {//Strongly Connected Component Tarjan Algorithm : dfs + stack
    // if dfs return lowest discover(yet scc X) == my discover, pop stack until me(make scc)
    discover[node] = visitcount++;
    st.push(node);
    int ret = discover[node];
    for (int i = 0; i < edge[node].size(); i++) {
        int next = edge[node][i];
        if (discover[next] == 0)//not visit
            ret = min(ret, dfs(next));
        else if (scc[next] == 0)//not in scc
            ret = min(ret, discover[next]);
    }
    if (ret == discover[node]) {//lowest discover is mine
        while (st.top()!=node) {
            scc[st.top()] = node;
            st.pop();
        }
        st.pop();
        scc[node] = node;
    }
    return ret;
}
int main() {
    FASTIO;
    cin >> N >> M;
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        if (a > 0 && b > 0) {//하나 false일 경우 다른 하나 true여야만함
            edge[a + N].push_back(b);
            edge[b + N].push_back(a);
        }
        else if (a > 0 && b < 0) {
            edge[a + N].push_back(-b + N);
            edge[-b].push_back(a);
        }
        else if (a < 0 && b>0) {
            edge[b + N].push_back(-a + N);
            edge[-a].push_back(b);
        }
        else if (a < 0 && b < 0) {
            edge[-a].push_back(-b + N);
            edge[-b].push_back(-a + N);
        }
    }
    for (int i = 1; i <= 2 * N; i++) {
        if (discover[i] == 0)
            dfs(i);
    }
    bool flag = 1;
    for (int i = 1; i <= N; i++) {
        if (scc[i] == scc[i + N]) {
            flag = 0;
            break;
        }
    }
    cout << flag;
    return 0;
}