#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, M, cnt = 0;
priority_queue<int> ten, el;
int main() {
    FASTIO;
    int temp;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp == 10)
            cnt++;
        else if (temp % 10 == 0)
            ten.push(-temp);
        else if (temp>10)
            el.push(-temp);
    }
    int top;
    while (!((ten.empty() && el.empty()) || M == 0)) {
        if (!ten.empty()) {
            top = ten.top();
            ten.pop();
            if (-top == 20)
                cnt += 2;
            else {
                cnt += 1;
                ten.push(top + 10);
            }
        }
        else {
            top = el.top();
            el.pop();
            if (-top - 10 < 10)
                cnt++;
            else {
                el.push(top + 10);
                cnt++;
            }
        }
        M--;
    }
    cout << cnt;
    return 0;
}