#include <bits/stdc++.h>
using namespace std;
int T;
vector<int> one;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    string s;
    for (int t = 0; t < T; t++) {
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                cnt++;
            else {
                one.push_back(cnt);
                cnt = 0;
            }
        }
        if (cnt != 0)
            one.push_back(cnt);
        sort(one.begin(), one.end());
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (one.empty())
                break;
            if (i % 2 == 0)
                result += one.back();
            one.pop_back();
        }
        cout << result << '\n';
    }
    return 0;
}