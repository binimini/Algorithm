#include <bits/stdc++.h>
using namespace std;
priority_queue<int> pq;
int N, result = 0;
pair<int,int> arr[200000];
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].first>>arr[i].second;
    }
    sort(arr, arr + N);
    int cnt = 0;
    while (cnt<=N-1) {
        if (pq.empty()) {
            pq.push(-arr[cnt].second);
        }
        else {
            while (!pq.empty()&&-pq.top() <= arr[cnt].first) {
                pq.pop();
            }
            pq.push(-arr[cnt].second);
        }
        cnt++;
        int size = pq.size();
        result = max(result, size);
    }
    cout << result;
    return 0;
}