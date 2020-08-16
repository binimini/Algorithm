#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i<b; i++)
#define FAST std::ios_base::sync_with_stdio(0); cin.tie(0);
int T, N;
string S;
int main() {
    FAST;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N >> S;
        vector<pair<char,int>> v;
        int cnt = 0;
        char temp = 'O';
        bool CH = 0;
        if (S[S.size() - 1] == S[0])
            CH = 1;
        FOR(i, 0, N) {
            if (temp == S[i]) cnt++;
            else {
                if (temp != 'O') {
                    v.push_back(make_pair(S[i-1],cnt));
                }
                temp = S[i];
                cnt = 1;
            }
        }
        v.push_back(make_pair(S[N-1],cnt));
        int result = 0;
        if (CH&&v.size()!=1) {// 1 아니고 앞뒤 같은 문자인 경우 앞뒤 합친다
            v[0].second = v.back().second + v[0].second;
            v.pop_back();
        }
        FOR(i, 0, v.size()) {
            if (v[i].second >= 3) {
                result += v[i].second / 3;// 쪼개는 방법 바꾸는 문자를 경계로 3개이상되지 않도록 쪼개는 것 
                //3 = 1 + (1) +1 4 = 2 + (1) +  5 = 2 +(1) + 2 6 = 1+ (1) + 2 + (1) + 1
                // 이런식으로 3의 배수 단위로 바꾸는 문자 개수가 추가 된다. 
            }
        }
        if (v.size()==1&&N%3!=0) {//모두 하나일때 3의 배수인 경우는 1 + (1) + 1 형태 되어서 앞뒤 합이 2이므로 추가로 쪼개지 않아도 된다.
            result++;
        }
        cout << result << '\n';
    }
    return 0;
}