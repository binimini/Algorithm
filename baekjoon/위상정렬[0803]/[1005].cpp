#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
int T, N, K, W;
int deg[1001] = { 0 }, time_info[1001], time_spend[1001] = { 0 };
vector<int> edge[1001];
queue<int> q;
int topologysort() {
	for (int i = 1; i <= N; i++) {
		if (deg[i] == 0) {
			q.push(i);
			time_spend[i] = time_info[i];
		}
	}
	for (int i = 0; i < N; i++) {
		int x = q.front();
		q.pop();
		if (x == W) {
			while (!q.empty()) {
				q.pop();
			}
			return time_spend[x];
		}
		for (int j = 0; j < edge[x].size(); j++) {
			int y = edge[x][j];
			deg[y]--;
			time_spend[y] = max(time_spend[y], time_spend[x] + time_info[y]);
			if (deg[y] == 0){
				q.push(y);
			}
		}
	}
}
int main() {//ACM Craft
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> K;
		for (int j = 1; j <= N; j++) {
			cin >> time_info[j];
			time_spend[j] = 0;
			edge[j].clear();
			deg[j] = 0;
		}
		int x, y;
		for (int j = 0; j < K; j++) {
			cin >> x >> y;
			edge[x].push_back(y);
			deg[y]++;
		}
		cin >> W;
		cout << topologysort() << '\n';
	}
	return 0;
}