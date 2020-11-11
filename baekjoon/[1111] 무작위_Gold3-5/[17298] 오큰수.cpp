#include <bits/stdc++.h>
using namespace std;
int N, arr[1000000],ans[1000000];
stack<int> s;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = N - 1; i >= 0; i--) {
        while (!s.empty() && arr[i] >= s.top()) {
            s.pop();
        }
        if (s.empty())
            ans[i] = -1;
        else
            ans[i] = s.top();
        s.push(arr[i]);
    }
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}