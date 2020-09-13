#include <bits/stdc++.h>
using namespace std;

int main() {
    string S;
    getline(cin, S);
    int cnt = 0;
    vector<pair<int, int>> v;
    int s = 0, e = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == ' ' || S[i] == '-') {
            v.push_back(make_pair(s, e-1));
            s = i + 1;
        }
        e++;
    }
    v.push_back(make_pair(s, e-1));
    cnt = v.size();
    bool flag1 = 0, flag2 = 0;
    for (int j = 0; j < v.size(); j++) {
        flag1 = 0, flag2 = 0;
        int i = v[j].first;
        if (S[i] == 'c' || S[i] == 'j' || S[i] == 'n' || S[i] == 'm' || S[i] == 't' || S[i] == 's' || S[i] == 'l' || S[i] == 'd')
                flag1 = true;
        else if (S[i] == 'q')
                flag2 = true;
        i++;
        if (flag2) {
            if (i <= v[j].second&&S[i] == 'u') {
                if ((i + 1) <= v[j].second&&S[i + 1] == '\'') {
                    if ((i + 2) <= v[j].second && (S[i + 2] == 'a' || S[i + 2] == 'e' || S[i + 2] == 'o' || S[i + 2] == 'u' ||S[i+2]=='i'|| S[i + 2] == 'h')) {
                        cnt++;
                    }
                }
            }
        }
        else if (flag1) {
            if  (i<= v[j].second && S[i] == '\'') {
                if ((i + 1) <= v[j].second && (S[i + 1] == 'a' || S[i + 1] == 'e' || S[i + 1] == 'o' || S[i + 1] == 'u' || S[i + 1] == 'i' || S[i + 1] == 'h')) {
                    cnt++;
                }
            }
        }
    }
    cout << cnt << "\n";
    return 0;
}