#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, degree[32001] = { 0 }, result[32000];
vector<int> edge[32001];
queue<int> q;

void topologysort() {//��������
	for (int i = 0; i < N; i++) {
		if (q.empty())//����Ŭ�����ϴ°��
			return;
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int j = 0; j < edge[x].size(); j++) {
			degree[edge[x][j]]--;
			if (degree[edge[x][j]] == 0)
				q.push(edge[x][j]);
		}
	}

}

int main() {//�� ����
	std::ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> M;
	int cond_x, x;
	for (int i = 0; i < M; i++) {
		cin >> cond_x >> x;
		edge[cond_x].push_back(x);
		degree[x]++;
	}
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0)
			q.push(i);
	}
	topologysort();
	for (int i = 0; i < N; i++) {
		cout << result[i] << ' ';
	}
	cout << '\n';
	return 0;
}