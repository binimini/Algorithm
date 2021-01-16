#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
string s, p;
vector<int> res;
int N, M, pi[1000000];
void getPi() {//same way as kmp
    int j = 0;
    for (int i = 1; i < M; i++) {
        while (j > 0 && p[i] != p[j])//j-1 is ok and  p[i] != p[j]
            j = pi[j - 1];//j : max substring length (~j-1, is index -> next char)
        if (p[i] == p[j])
            pi[i] = ++j;//j : index->length 
    }
}
void KMP() {//KMP algorithm (searching string)
    int j = 0;
    for (int i = 0; i < N; i++) {
        while (j > 0 && s[i] != p[j])
            j = pi[j - 1];
        if (s[i] == p[j]) {
            if (j == M - 1) {//found match
                res.push_back(i - (M - 1));
                j = pi[j];//!!
            }
            else {//keep going
                j++;
            }
        }
    }
}
int main() {
    FASTIO;
    getline(cin, s);//string can include blank
    getline(cin, p);//getline(cin, string variable);
    N = s.size();
    M = p.size();
    getPi();
    KMP();
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i]+1 << " ";//index 1~N, not 0~N-1
    }
    return 0;
}