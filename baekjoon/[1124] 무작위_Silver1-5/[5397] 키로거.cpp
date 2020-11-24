#include <bits/stdc++.h>
using namespace std;
int T;
stack<char> st1, st2;
string S;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> S;
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == '<') {
                if (!st1.empty()) {
                    st2.push(st1.top());
                    st1.pop();
                }
            }
            else if (S[i] == '>') {
                if (!st2.empty()) {
                    st1.push(st2.top());
                    st2.pop();
                }
            }
            else if (S[i] == '-') {
                if (!st1.empty()) {
                    st1.pop();
                }
            }
            else
                st1.push(S[i]);
        }
        vector<char> result;
        while (!st1.empty()) {
            result.push_back(st1.top());
            st1.pop();
        }
        while (!result.empty()) {
            cout << result.back();
            result.pop_back();
        }
        while (!st2.empty()) {
            cout << st2.top();
            st2.pop();
        }
        cout << "\n";
    }

    return 0;
}