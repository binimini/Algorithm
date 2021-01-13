#include <bits/stdc++.h>
using namespace std;
string s, temp = "";
int res = 0, beminus = 0;
int main() {
    cin >> s;
    bool minus_flag = 0 , temp_minus = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            temp += s[i];
        else {
            if (temp_minus || minus_flag)
                beminus += stoi(temp);
            else
                res += stoi(temp);
            if (s[i] == '+')
                temp_minus = 0;
            else if (s[i] == '-')
                temp_minus = 1, minus_flag = 1;
            temp = "";
        }
    }
    if (temp_minus || minus_flag)//마지막 숫자 처리
        beminus += stoi(temp);
    else
        res += stoi(temp);
    cout << res - beminus;
    return 0;
}