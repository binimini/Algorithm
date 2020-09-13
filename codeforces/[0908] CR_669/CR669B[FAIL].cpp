#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i<b; i++)
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T, N;
int arr[1000];
bool visited[1001] = { 0 };
priority_queue <pair<int, int>> pq1;
priority_queue <pair<int, int>> pq2;
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N;
        for (int i = 0; i <= 1000; i++) {
            visited[i] = 0;
        }
        int M = 0;
        FOR(i, 0, N) {
            cin >> arr[i];
            M = max(M, arr[i]);
        }
        for (int i = M; i >=1; i--) {
            if (M % i == 0) {
                visited[i] = 1;
            }
        }
        for (int i = 0; i < N; i++) {
            if (arr[i] == M) continue;
            else {
                for (int j = arr[i]; j >= 1; j--) {
                    if (visited[j] == 1 && arr[i] % j == 0) {
                        pq1.push(make_pair(j, arr[i]));
                        break;
                    }
                }
            }
        }
        cout << M << " ";
        int temp = 1;
        while (!(pq1.empty() && pq2.empty())) {
            if (!pq1.empty()) {
                temp = pq1.top().first;
                for (int i = temp; i > 1; i--) {
                    if (temp % i != 0)
                        visited[i] = 0;
                    else visited[i] = 1;
                }
                cout << pq1.top().second << " ";
                pq1.pop();
                while (!pq1.empty()) {
                    for (int i = pq1.top().first; i >= 1; i--) {
                        if (visited[i] == 1 && pq1.top().first % i == 0) {
                            pq2.push(make_pair(i, pq1.top().second));
                            pq1.pop();
                            break;
                        }
                    }
                }
            }
            else if (!pq2.empty()) {
                temp = pq2.top().first;
                for (int i = temp; i >= 1; i--) {
                    if (temp % i != 0)
                        visited[i] = 0;
                    else visited[i] = 1;
                }
                cout << pq2.top().second << " ";
                pq2.pop();
                while (!pq2.empty()) {
                    for (int i = pq2.top().first; i >= 1; i--) {
                        if (visited[i] == 1 && pq2.top().first % i == 0) {
                            pq1.push(make_pair(i, pq2.top().second));
                            pq2.pop();
                            break; 
                        }
                    }
                }
            }
        }
        cout << "\n";
    }
    return 0;
}