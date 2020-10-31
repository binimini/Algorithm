#include <bits/stdc++.h>
using namespace std;
stack<pair<int,int>> s;
int N;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int temp, temp_cnt = 1;
    long long int cnt = 0;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        temp_cnt = 1;
        if (s.empty())
            s.push(make_pair(temp,1));
        else if (s.top().first > temp) {
            s.push(make_pair(temp, 1));
            cnt++;
        }
        else if (s.top().first <= temp) {
            while (!s.empty() && s.top().first < temp) {
                cnt += s.top().second;
                s.pop();
            }
            if (!s.empty()) {
                if (s.top().first == temp) {
                    pair<int, int> temp_p = s.top();
                    cnt += temp_p.second;
                    s.pop();
                    if (!s.empty())
                        cnt++;
                    temp_p.second++;
                    s.push(temp_p);
                }
                else {
                    cnt++;
                    s.push(make_pair(temp, 1));
                }
            }
            else
                s.push(make_pair(temp, 1));
        }
    }
    cout << cnt << "\n";
    return 0;
}