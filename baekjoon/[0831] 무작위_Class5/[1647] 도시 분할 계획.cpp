#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
int N, M;
int parent[100001];
vector<tuple<int,int,int>> v;
bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {
    return get<2>(a) < get<2>(b);
}
int getparent(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = getparent(parent[x]);
}
bool sameparent(int x, int y) {
    x = getparent(x);
    y = getparent(y);
    return x == y;
}
void unionparent(int x, int y) {
    x = getparent(x);// 유니온할때 노드 값으로 접근하면
    //이미 루트 둘 다 만들어져있는 리프 노드들이 합쳐질 때
    //리프노드만 루트 중 하나로 합쳐지고 나머지 루트와 노드들은 다른 집합으로 남겨짐
    //따라서 루트를 변경
    y = getparent(y);
    if (x < y)
        parent[y] = x;
    else parent[x] = y;
}

int main() {//도시 분할 계획
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int a, b, c;
    for (int i = 0; i < M; i++) {
        cin >> a >> b >> c;
        v.push_back(make_tuple(a, b, c));
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 1; i <= N; i++) {
        parent[i] = i;
    }
    int sum = 0;
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (cnt >= N - 2)
            break;
        if (!sameparent(get<0>(v[i]), get<1>(v[i]))) {//크루스칼 알고리즘
            cnt++;
            sum += get<2>(v[i]);
            unionparent(get<0>(v[i]), get<1>(v[i]));
        }
    }
    cout << sum;
    return 0;
}