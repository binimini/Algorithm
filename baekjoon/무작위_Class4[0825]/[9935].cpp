#include <iostream>
#include <deque>
using namespace std;
string S, X;
deque<pair<char, int>> dq;
int main() {//문자열 폭발
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> S >> X;
    int cnt = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == X[cnt]) {
            cnt++;
            if (cnt == X.size()) {
                for (int j = 1; j < X.size(); j++) {
                    dq.pop_back();
                }
                if (!dq.empty())
                    cnt = dq.back().second;
                else cnt = 0;
            }
            else dq.push_back(make_pair(S[i], cnt));
        }
        else {
            if (S[i] == X[0])
                cnt = 1;
            else cnt = 0;
            dq.push_back(make_pair(S[i], cnt));
        }
    }
    int size = dq.size();
    for (int i = 0; i < size; i++) {
        cout << dq.front().first;
        dq.pop_front();
    }
    if (!size)
        cout << "FRULA";
    return 0;
}