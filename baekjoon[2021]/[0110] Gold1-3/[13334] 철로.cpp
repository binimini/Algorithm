#include <bits/stdc++.h>
using namespace std;
int N, D, result = 0;
priority_queue<int> pq;
vector<pair<int, int>> v;
bool compare(pair<int,int> a, pair<int,int> b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        v.push_back(make_pair(min(a, b), max(a,b)));
    }
    cin >> D;
    sort(v.begin(), v.end(), compare);//왼쪽 점 기준 정렬 시 start = 1 d = 3,
    //(2,5) (3,4)에서 (3,4)취급 못하고 바로 5포함으로 넘어감
    //따라서 오른쪽 점 기준으로 정렬하고 왼쪽 점 체크로 포함여부 체크!!!
    int end = -100000001, size;
    for (int i = 0; i < N; i++) {
        if (v[i].second == end) {
            pq.push(-v[i].first);
        }
        else {
            end = v[i].second;
            pq.push(-v[i].first);
        }

        while (!pq.empty()&&-pq.top() < end - D) {
            pq.pop();
        }
        size = pq.size();
        result = max(result, size);
    }
    cout << result;
    return 0;
}