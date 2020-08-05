#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int N, M, deg[32001] = { 0 }, result[32001];
vector<int> edge[32001];
queue<int> q;
deque<int> tosort;
void tpsort() {
	for (int i = 1; i <= N; i++) {
		if (deg[i] == 0)
			tosort.push_back(i);
	}
	q.push(tosort.front());
	tosort.pop_front();
	for (int i = 0; i < N; i++) {
		if (q.empty()) return;
		int x = q.front();
		result[i] = x;
		q.pop();
		for (int j = 0; j < edge[x].size(); j++) {
			int y = edge[x][j];
			deg[y]--;
			if (deg[y] == 0) {
				int s = 0, e = tosort.size(), m = 0;
				if (e > 0) {
					while (e - s > 0) {
						m = (s + e) / 2;
						if (tosort[m] <= y) s = m + 1;
						else if (tosort[m] > y) e = m;
					}
					tosort.insert(tosort.begin() + s, y);
				}
				else tosort.push_back(y);
			}
		}
		if (!tosort.empty()) {
			q.push(tosort.front());
			tosort.pop_front();
		}
	}
}

int main() {//문제집
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int x, y;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		edge[x].push_back(y);
		deg[y]++;
	}
	tpsort();
	for (int i = 0; i < N; i++) {
		cout << result[i] << " ";
	}
	cout << '\n';
	return 0;
}