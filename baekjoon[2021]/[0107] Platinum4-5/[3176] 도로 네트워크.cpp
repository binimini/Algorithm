#include <bits/stdc++.h>
using namespace std;
int N, K, depth[100001], max_level;
int p[100001][20], m[100001][20], M[100001][20];
vector<pair<int,int>> edge[100001];
void getTree(int node, int parent, int cost) {
    depth[node] = depth[parent] + 1;
    p[node][0] = parent;
    m[node][0] = cost;
    M[node][0] = cost;

    for (int i = 1; i <= max_level; i++) {
        int temp = p[node][i - 1];
        p[node][i] = p[temp][i - 1];//조상 없는 범위일경우 0으로 정해져서 상관없지만 최소 최대값은? -> 깔끔하게 한 번에 처리
        m[node][i] = 1000001;
        M[node][i] = 0;
    }

    for (int i = 0; i < edge[node].size(); i++) {
        if (edge[node][i].first != parent)
            getTree(edge[node][i].first, node, edge[node][i].second);
    }
}
void getMm() {//최소최대값처리
    for (int i = 1; i <= max_level; i++) {
        for (int j = 1; j <= N; j++) {
            int temp = p[j][i - 1];
            m[j][i] = min(m[j][i-1], m[temp][i - 1]);//m[j][1] <- m[j][0] m[m[j][0][0]
            //m[j][2] <- m[j][1] m[m[j][1]][1] ... -> O(logN)
            M[j][i] = max(M[j][i-1], M[temp][i - 1]);
        }
    }
}
int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    max_level = (int)ceil(log2(100001) + 1);//최대깊이?

    cin >> N;
    int a, b, c;
    for (int i = 0; i < N - 1; i++) {
        cin >> a >> b >> c;
        edge[a].push_back(make_pair(b, c));
        edge[b].push_back(make_pair(a, c));
    }
    depth[0] = -1;
    getTree(1, 0, 0);
    getMm();
    
    cin >> K;
    for (int i = 0; i < K; i++) {
        int mres = 1000001, Mres = 0;//초기화 잊지말것, 갱신때마다 a b 값 뿐 아니라 res값도 같이 비교
        cin >> a >> b;
        if (depth[a] != depth[b]) {//depth 다를때만
            if (depth[a] > depth[b]) {//depth[a]<=[b]
                int temp = a;
                a = b;
                b = temp;
            }
            for (int i = max_level; i >= 0; i--) {
                if (depth[a] <= depth[p[b][i]]) {//depth같게하기
                    mres = min(mres, m[b][i]);
                    Mres = max(Mres, M[b][i]);
                    b = p[b][i];
                }
            }
        }
        if (a != b) {//다를때만
            for (int i = max_level; i >= 0; i--) {
                if (p[a][i] != p[b][i]) {
                    mres = min(mres,min(m[a][i], m[b][i]));
                    Mres = max(Mres,max(M[a][i], M[b][i]));
                    a = p[a][i], b = p[b][i];//다른조상일때
                }
            }
            mres = min(mres,min(m[a][0], m[b][0]));//공통조상으로 위치 헷갈리지 말것!!
            Mres = max(Mres,max(M[a][0], M[b][0]));
        }
        cout << mres << " " << Mres << "\n";
    }
    return 0;
}