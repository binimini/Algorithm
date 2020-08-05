#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int N, result[11] = { 0 }, deg[11] = { 0 }, l_deg[11] = { 0 };
bool visited[10] = { 0 };
vector<int> edge[11], l_edge[11];
priority_queue<int,vector<int>, greater<int>> q;
void l_tpsort() {
	for (int i = 1; i <= N + 1; i++) {
		if (l_deg[i] == 0)
			q.push(i);
	}
	for (int i = 1; i <= N + 1; i++) {
		int x = q.top();
		q.pop();
		if (result[x] == 0) {
			for (int i = 9; i >=0; i--) {
				if (visited[i] == 0) {
					result[x] = i;
					visited[i] = 1;
					break;
				}
			}
		}
		for (int j = 0; j < l_edge[x].size(); j++) {
			int y = l_edge[x][j];
			l_deg[y]--;
			if (l_deg[y] == 0) {
				q.push(y);
			}
		}
	}
}
void tpsort() {
	for (int i = 1; i <= N+1; i++) {
		if (deg[i] == 0)
			q.push(i);
	}
	for (int i = 1; i <= N+1; i++) {
		int x = q.top();
		q.pop();
		if (visited[0] == 0) {
			result[x] = 0;
			visited[0] = 1;
		}
		else if (result[x] == 0) {
			for (int i = 0; i < 10; i++) {
				if (visited[i] == 0) {
					result[x] = i;
					visited[i] = 1;
					break;
				}
			}
		}
		for (int j = 0; j < edge[x].size(); j++) {
			int y = edge[x][j];
			deg[y]--;
			if (deg[y] == 0) {
				q.push(y);
			}
		}
	}
}
int main() {//부등호
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	char temp;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		if (temp == '<') {
			edge[i].push_back(i + 1);
			deg[i + 1]++;
			l_edge[i + 1].push_back(i);
			l_deg[i]++;
		}
		else if (temp == '>') {
			edge[i + 1].push_back(i);
			deg[i]++;
			l_edge[i].push_back(i + 1);
			l_deg[i + 1]++;
		}
	}
	l_tpsort();
	for (int i = 1; i <= N+1; i++) {
		cout << result[i];
	}
	cout << '\n';
	for (int i = 0; i < 10; i++) {
		visited[i] = 0;
		result[i + 1] = 0;
	}
	while (!q.empty()) {
		q.pop();
	}
	tpsort();
	for (int i = 1; i <= N + 1; i++) {
		cout << result[i];
	}
	cout << '\n';
	return 0;
}