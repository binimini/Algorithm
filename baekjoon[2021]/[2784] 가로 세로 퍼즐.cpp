#include <bits/stdc++.h>
using namespace std;
char arr[4][4];
string input[6];
int use_word[3];
bool flag = 0, use[6] = { 0 }, check[6] = { 0 };
vector<string> ans;
void solve(int cnt) {
    if (cnt == 3) {
        for (int i = 0; i < 6; i++) {
            check[i] = 0;
        }
        for (int i = 0; i < 3; i++) {
            check[use_word[i]] = 1;
            for (int j = 0; j < 3; j++) {
                arr[i][j] = input[use_word[i]][j];
            }
        }
        for (int j = 0; j < 3; j++) {
            string temp = "";
            for (int i = 0; i < 3; i++) {
                temp += input[use_word[i]][j];
            }
            for (int i = 0; i < 6; i++) {
                if (check[i] == 0 && temp == input[i]) {
                    check[i] = 1;
                    break;
                }
            }
        }
        for (int i = 0; i < 6; i++) {
            if (check[i] == 0) {
                return;
            }
        }
        ans.push_back(input[use_word[0]] + input[use_word[1]] + input[use_word[2]]);
        return;
    }
    for (int i = 0; i < 6; i++) {
        if (use[i]) continue;
        use[i] = 1;
        use_word[cnt] = i;
        solve(cnt + 1);
        use[i] = 0;
    }
}
int main() {
    for (int i = 0; i < 6; i++) {
        cin >> input[i];
        if (input[i].size() != 3)
            flag = 1;
    }
    solve(0);
    if (flag||ans.size()==0)
        cout << 0;
    else {
        sort(ans.begin(), ans.end());
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << ans[0][i * 3 + j];
            }
            cout << '\n';
        }
    }
    return 0;
}