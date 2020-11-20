#include <bits/stdc++.h>
using namespace std;
string S;
int main() {
    cin >> S;
    stack<char> s;
    int result = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(') {
            if (S[i + 1] == ')')
                result += s.size();
            else {
                s.push('(');
                result++;
            }
        }
        else if (S[i] == ')') {
            if (S[i - 1] != '(')
                s.pop();
        }
    }
    cout << result;
    return 0;
}