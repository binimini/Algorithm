#include <bits/stdc++.h>
using namespace std;
int N, result = 0;
vector<char> v;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    string s;
    for (int i = 0; i < N; i++) {
        v.clear();
        cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (v.empty())
                v.push_back(s[j]);
            else {
                if (v.back() == s[j])
                    v.pop_back();
                else
                    v.push_back(s[j]);
            }
        }
        if (v.empty())
            result++;
    }
    cout << result;
    return 0;
}