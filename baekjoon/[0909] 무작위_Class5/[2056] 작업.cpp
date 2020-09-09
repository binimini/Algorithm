#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N;
int time[10001], deg[10001], cost[10001] = { 0 };
queue<pair<int,int>> q;
vector<int> edge[10001];
int T = 0;
void tpsort() {
    while (!q.empty()) {
        int x = q.front().first;
        int ex = q.front().second;
        q.pop();

        T = max(T, ex + time[x]);
        
        for (int i = 0; i < edge[x].size(); i++) {
            cost[edge[x][i]] = max(cost[edge[x][i]], ex + time[x]);
            
            if (--deg[edge[x][i]] == 0)
                q.push(make_pair(edge[x][i], cost[edge[x][i]]));
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int x = 1; x <= N; x++) {
        cin >> time[x];
        
        int temp, y;
        cin >> temp;
        for (int j = 0; j < temp; j++) {
            cin >> y;
            deg[x]++;
            edge[y].push_back(x);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        if (deg[i] == 0)
            q.push(make_pair(i,0));
    }
    tpsort();
    
    cout << T << '\n';
    
    return 0;
}