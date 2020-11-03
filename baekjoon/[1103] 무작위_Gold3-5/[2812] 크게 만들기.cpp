#include <bits/stdc++.h>
using namespace std;
stack<int> s;
int N, K;
string num;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> K;
    cin >> num;
    for (int i = 0; i < N; i++) {
        if (s.empty())
            s.push(num[i] - '0');
        else if (s.top() < num[i]-'0') {
            while (!s.empty()&&s.top()<num[i]-'0') {
                if (s.size() -1 + N - i < N - K)
                    break;
                s.pop();
            }
            s.push(num[i]-'0');
        }
        else if (s.top() >= num[i]-'0'&&s.size()<N-K) {
            s.push(num[i]-'0');
        }
    }
    stack<int> result;
    while (!s.empty()) {
        result.push(s.top());
        s.pop();
    }
    while (!result.empty()) {
        cout << result.top();
        result.pop();
    }
    return 0;
}