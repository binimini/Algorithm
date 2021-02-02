#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);

int N,people[10001], dp[10001][2][2], INF = 987654321;
bool visited[10001] = { 0 };
vector<int> edge[10001];
int solve(int n, bool g, bool prev) {
    if (dp[n][g][prev] != -1)
        return dp[n][g][prev];

    bool can_go = 0;
    vector<pair<int, int>> v;//vector for calculting 
    int& r = dp[n][g][prev];//reference
    r = 0;//init
    for (int i = 0; i < edge[n].size(); i++) {
        int next = edge[n][i];
        if (visited[next]) continue;
        can_go = 1;
        visited[next] = 1;

        if (!g)
            v.push_back(make_pair(solve(next, 0, g), solve(next, 1, g)));
        else if (g)//if great, next must be not great!!!
            r += solve(next, 0, g);
        
        visited[next] = 0;//backtracking
    }
    if (!can_go)//can't go anywhere -> return
        return r = (g) ? people[n] : 0;//save in dp!!!

    if ((!g)&&(!prev)) {//if not great and previous node also not great -> at least one next must be great!!!
        pair<int, int> loss_min = { INF, 0 };//find minimum (notgreat-great)
        for (int i = 0; i < v.size(); i++) {
            if (loss_min.first > v[i].first - v[i].second) {
                loss_min.first = v[i].first - v[i].second;
                loss_min.second = i;
            }
        }
        for (int i = 0; i < v.size(); i++) {
            if (i != loss_min.second)
                r += max(v[i].first, v[i].second);
        }
        r += v[loss_min.second].second;//at least one great in minimum loss O(M(=adj cnt))??
    }
    else if ((!g)&&prev) {//not great but prev great, so next can great or not great!!!!!
        for (int i = 0; i < v.size(); i++) {
            r += max(v[i].first, v[i].second);
        }
    }
    return r = g ? r + people[n] : r;//if n is great, add number of people
}
int main() {
    FASTIO;//input
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> people[i];
    }
    int a, b;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b;
        edge[a].push_back(b);//no direction
        edge[b].push_back(a);
    }

    memset(dp, -1, sizeof(dp));//dp must include dp[][][prev]!!!
    //0-0(me)<-(next)atleastone 
    //1-0(me)<-(next)don'tcare      saparate impossible!!!!! ( me-0 same dp)
    visited[1] = 1;//start node
    cout <<max(solve(1, 0, 0), solve(1, 1, 0));
    return 0;
}