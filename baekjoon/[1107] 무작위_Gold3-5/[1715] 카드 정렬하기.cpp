#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int N;
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        pq.push(-temp);
    }
    int result = 0;
    int sum;
    while (pq.size() != 1) {
        sum = pq.top();
        pq.pop();
        sum += pq.top();
        pq.pop();
        result -= sum;
        pq.push(sum);
    }
    cout << result;
    return 0;
}