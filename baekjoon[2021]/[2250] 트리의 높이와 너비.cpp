#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, deg[10001] = { 0 }, p[10001], INF = 10001, maxlev = 1;
pair<int, int> tree[10001], level[10001];
bool visited[10001] = { 0 };
void preorder(int root) {
    p[root] = INF;
    int cnt = 1, lev = 1, left, right;
    while (root!=INF) {
        //왼, 왼 갈 수 없으면 자신, 자신 갈 수 없으면 오른쪽, 갈데없으면 parent로
        left = tree[root].first;
        right = tree[root].second;
        if (left != -1 && !visited[left]) {
            root = left;
            lev++;
            maxlev = max(lev, maxlev);
        }
        else if (!visited[root]) {
            visited[root] = 1;
            level[lev].first = min(cnt, level[lev].first);
            level[lev].second = max(cnt, level[lev].second);
            cnt++;
        }
        else if (right != -1 && !visited[right]) {
            root = right;
            lev++;
            maxlev = max(lev, maxlev);
        }
        else {
            root = p[root];
            lev--;
        }
        
    }
}
int main() {
    FASTIO;
    cin >> N;
    int node, left, right;
    for (int i = 1; i <= N; i++) {
        level[i].first = INF, level[i].second = 0;
        cin >> node >> left >> right;
        tree[node].first = left; tree[node].second = right;
        p[left] = node, p[right] = node;
        deg[left]++, deg[right]++;
    }
    for (int i = 1; i <= N; i++) {
        if (deg[i] == 0)
            preorder(i);
    }
    pair<int, int> res = { 0,0 };
    int temp;
    for (int i = 1; i <= maxlev; i++) {
        temp = level[i].second - level[i].first + 1;
        if (temp > res.second)
            res.second = temp, res.first = i;
    }
    cout << res.first << " " << res.second << "\n";
    return 0;
}