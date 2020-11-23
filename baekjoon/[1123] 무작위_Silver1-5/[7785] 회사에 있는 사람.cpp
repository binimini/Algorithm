#include <bits/stdc++.h>
using namespace std;
map<string, int> m;
int N;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    string s, status;
    for (int i = 0; i < N; i++) {
        cin >> s;
        cin >> status;
        if (status == "enter")
            m[s] = 1;
        else if (status == "leave")
            m.erase(s);
    }
    for (map<string, int>::reverse_iterator iter = m.rbegin(); iter != m.rend(); iter++) {
        cout << iter->first << "\n";
    }
    return 0;
}