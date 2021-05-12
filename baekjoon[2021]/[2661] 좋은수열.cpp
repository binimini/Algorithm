#include <bits/stdc++.h>
using namespace std;
int N;
bool flag = 0;
string answer;
bool check(string str) {
    for (int i = 2; i <= str.size(); i += 2) {
        for (int j = 0; j <= str.size() - i; j++) {
            string temp1 = str.substr(j, i/2);
            string temp2 = str.substr(j + i / 2, i / 2);
            if (temp1 == temp2)
                return false;
        }
    }
    return true;
}
void solve(string ans, int n) {
    if (flag)
        return;
    if (n == N) {
        answer = ans;
        flag = 1;
        return;
    }
    for (char i = '1'; i <= '3'; i++) {
        if (flag)
            return;
        if (check(ans + i))
            solve(ans + i, n + 1);
    }
}

int main() {
    cin >> N;
    solve("", 0);
    cout << answer;
    return 0;
}