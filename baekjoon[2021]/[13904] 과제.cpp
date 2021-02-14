#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N;
priority_queue<int> pq;
vector<pair<int, int>> arr;
int main() {
    FASTIO;
    cin >> N;
    int d, w;
    for (int i = 0; i < N; i++) {
        cin >> d >> w;
        arr.push_back(make_pair(d, w));
    }
    sort(arr.begin(), arr.end());
    int day = arr.back().first, score = 0;
    while (1) {
        if (day == 0)
            break;
        while (!arr.empty() && arr.back().first == day) {
            pq.push(arr.back().second);
            arr.pop_back();
        }
        if (!pq.empty()) {
            score += pq.top();
            pq.pop();
        }
        day--;
    }
    cout << score;
    return 0;
}