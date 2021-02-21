#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T, N;
int pre[1000], in[1000], to_in[1001];//노드 번호 1-1000 to_in[1001]!!!
void postorder(int pre_start, int pre_end, int in_start, int in_end) {
    if (pre_start > pre_end || in_start > in_end) return;
    if (pre_start == pre_end ||in_start==in_end) {
        cout << pre[pre_start]<<" ";
        return;
    }
    int mid = to_in[pre[pre_start]];
    postorder(pre_start+1, pre_start+1+ (mid-1)-in_start, in_start, mid-1);
    postorder(pre_start + 1 + (mid - 1) - in_start+1, pre_end, mid+1, in_end);
    cout << in[mid]<<" ";
}
int main() {
    FASTIO;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 0; i < N; i++) {
            cin >> pre[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> in[i];
            to_in[in[i]] = i;
        }
        postorder(0, N - 1, 0, N - 1);
        cout << "\n";
    }

    return 0;
}