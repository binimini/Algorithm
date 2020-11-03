#include <bits/stdc++.h>
using namespace std;
priority_queue<int> p;
priority_queue<int> m;
int N;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int temp, z = 0;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (temp > 0)
            p.push(temp);
        else if (temp < 0)
            m.push(-temp);
        else
            z++;
    }
    int sum = 0, calcu;
    while (p.size() >= 2 || m.size() >= 2) {
        if (p.size() >= 2) {
            
            calcu = p.top();
            p.pop();
            if (calcu == 1 || p.top() == 1)
                sum += calcu + p.top();
            else {
                calcu *= p.top();
                sum += calcu;
            }
            p.pop();
        }
        else if (m.size() >= 2) {
            calcu = m.top();
            m.pop();
            calcu *= m.top();
            m.pop();
            sum += calcu;
        }
    }
    while (!p.empty()) {
        sum += p.top();
        p.pop();
    }
    while (!m.empty()) {
        if (z) {
            m.pop();
            z--;
        }
        else {
            sum -= m.top();
            m.pop();
        }
    }
    cout << sum;
    return 0;
}