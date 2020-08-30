#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int N, time[501], deg[501], result[501], ex[501] = { 0 };
vector<int> v[501];
queue<int> q;
void topology() {
    for (int i = 1; i <= N; i++) {
        if (deg[i] == 0)
            q.push(i);
    }
    for (int i = 1; i <= N; i++) {
        if (q.empty())
            break;
        int x = q.front();
        q.pop();
        result[x] = time[x] + ex[x];
        for (int j = 0; j < v[x].size(); j++) {
            deg[v[x][j]]--;
            ex[v[x][j]] = max(ex[v[x][j]], result[x]);
            if (deg[v[x][j]] == 0) {
                q.push(v[x][j]);
            }
        }
    }
    
}
int main() {//게임 개발
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        time[i] = temp;
        while (1) {
            cin >> temp;
            if (temp == -1)
                break;
            v[temp].push_back(i);
            deg[i]++;
        }
    }
    topology();
    for (int i = 1; i <= N; i++) {
        cout << result[i] << '\n';
    }
    return 0;
}