#include <iostream>
#include <stack>
using namespace std;
int arr[10000];
int idx[1000001];//값으로 접근하므로 범위 10^6
stack<int> s;
int i;
void solve(int start, int end) {//왼쪽 - 오른쪽 - node
    cout << start << " " << end << '\n';
    if (start > end) return;
    if (end >= i) return;
    solve(start + 1, idx[arr[start]] - 1);
    solve(idx[arr[start]], end);
    cout << arr[start] << '\n';
    return;

}
int main() {//이진 검색 트리
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, px = 1000001;
    i = 0;
    while (cin >> x) {
        arr[i] = x;
        if (x<=px)
            s.push(x);
        else {
            while (1) {
                if (!s.empty()&&s.top() < x) {
                    idx[s.top()] = i;
                    s.pop();
                }
                else break;
            }
            s.push(x);
        }
        i++;
        px = x;
    }
    for (int j = 0; j < i; j++) {
        if (idx[arr[j]] == 0)
            idx[arr[j]] = i;
    }
    solve(0,i-1);
    return 0;
}