#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M;
int tree[400001] = { 0 };
bool lazy[400001] = { 0 };
void update_lazy(int node, int start, int end) {//lazy값 먼저 적용 child 있을 경우 lazy값 물려주기(합의 경우 원소 수만큼)

    if (lazy[node] != 0) {
        tree[node] = end - start + 1 - tree[node];
        if (start != end) {
            int mid = (start + end) / 2;
            lazy[node * 2] = !lazy[node * 2];//전체 스위치 반전 여부!! 
            //직접 개수 계산하려하지말고 반전 여부만 처리해놓은뒤 개수 필요할때 반전 여부에 따라 계산한다.
            lazy[node * 2 + 1] = !lazy[node * 2 + 1];
        }
        lazy[node] = 0;
    }
}
void update_range(int node, int start, int end, int left, int right) {//query 함수랑 비슷한 형태
    
    update_lazy(node, start, end);//이미 lazy 있다면 처리

    if (right < start || end < left)
        return;
    int mid = (start + end) / 2;
    if (left <= start && end <= right) {//노드 범위가 구간 내에 전부 포함될 때만 lazy 이용 가능
        tree[node] = end - start + 1 - tree[node];
        if (start != end) {
            lazy[node * 2] = !lazy[node * 2];
            lazy[node * 2 + 1] = !lazy[node * 2 + 1];
        }
        return;
    }

    update_range(node * 2, start, mid, left, right);//아니면 더 파고들것
    update_range(node * 2 + 1, mid + 1, end, left, right);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];//tree[node] 업데이트 잊지말것!!

}
int query(int node, int start, int end, int left, int right) {

    update_lazy(node, start, end);//실제 값 구하기 전에도 lazy 남아 있을 수 있으므로 처리 필요!!
    
    if (right < start || end < left)
        return 0;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}
int main() {
    FASTIO;
    cin >> N >> M;
    int o, s, t;
    for (int i = 0; i < M; i++) {
        cin >> o >> s >> t;
        if (o == 0) {
            update_range(1, 0, N - 1, s - 1, t - 1);
        }
        else if (o == 1) {
            cout << query(1, 0, N - 1, s - 1, t - 1) << "\n";
        }
    }
    return 0;
}