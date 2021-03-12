#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, K, res = 0;
queue<pair<int, int>> q;
pair<int, int> arr[100000];
int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i].second >> arr[i].first;
    }
    sort(arr, arr + N);
    int left = arr[0].first, cnt = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i].first <= left + 2 * K) {
            cnt += arr[i].second;
            q.push(arr[i]);
        }
        else {
            while (!q.empty()&&!(left + 2 * K >= arr[i].first)) {//left 변경하면서 arr[i] 거리 안에 포함인지 보기
                cnt -= q.front().second;
                q.pop();
                if (q.empty())
                    break;
                left = q.front().first;
            }
            if (!(left + 2 * K >= arr[i].first))//결국 포함 안되면 arr[i]을 left로 시작
                left = arr[i].first;
            cnt += arr[i].second;
            q.push(arr[i]);
        }
        res = max(res, cnt);
    }
    cout << res;
    return 0;
}