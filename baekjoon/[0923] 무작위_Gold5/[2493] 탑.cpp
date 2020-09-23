#include <bits/stdc++.h>
using namespace std;
int N;
int arr[500001];
stack<int> s;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        while (!s.empty()) {
            if (arr[s.top()] > arr[i]) {
                cout << s.top() << " ";
                break;
            }
            else {
                s.pop();
            }
        }
        if (s.empty())
            cout << "0 ";
        s.push(i);
    }
    return 0;
}