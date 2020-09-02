#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define FOR(i,a,b) for (int i = a; i<b; i++)
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, K, bag[300000];
pair<int, int> jw[300000];
priority_queue<int> pq;
//정렬해서 lower_bound 사용?
int main() {
    FASTIO;
    cin >> N >> K;
    FOR(i, 0, N)
        cin >> jw[i].first >> jw[i].second;
    FOR(i, 0, K)
        cin >> bag[i];
    sort(bag, bag + K);
    sort(jw, jw + N);
    int j = 0;
    long long int result = 0;
    FOR(i, 0, K) {//이후 K당 보석은 모두 **공통** //정렬시 이전 검사 부분 검사 필요 없음
                  //무게 작은한에서 최대 가치 -> pq?
        while (j<N&&jw[j].first<=bag[i]) {
            pq.push(jw[j].second);
            j++;
        }
        if (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }
    }
    cout << result << "\n";
    return 0;
}