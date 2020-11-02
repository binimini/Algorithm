#include <bits/stdc++.h>
using namespace std;
priority_queue<long long int> pq;
int K, N;
long long int arr[100];
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
        pq.push(-arr[i]);
    }
    int cnt = 1;
    while(cnt!=N){
        long long int top = pq.top();
        pq.pop();
        cnt++;
        for (int j = 0; j < K; j++) {
            pq.push(top * arr[j]);

            if (top % arr[j]==0)
                break;
        }
    }
    cout << -pq.top();
    return 0;
}