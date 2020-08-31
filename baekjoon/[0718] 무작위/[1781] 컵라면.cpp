#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int N, visited[200000] = { 0 };
pair<int, int> info[200000];
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second > b.second;
    return a.first > b.first;
}
int main() {
    cin.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> info[i].first >> info[i].second;
    }
    sort(info, info + N, compare);
    long long int sum = 0;
    priority_queue<int> pq;
    int j = 0;
    for (int i = N; i > 0; i--) {
        while (j < N && i == info[j].first) {
            pq.push(info[j].second);
            j++;
        }
        if (!pq.empty()) {
            sum += pq.top();
            pq.pop();
        }
    }
    cout << sum;
    return 0;
}