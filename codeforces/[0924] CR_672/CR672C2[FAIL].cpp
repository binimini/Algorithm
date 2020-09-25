#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for(int i = a; i<b; i++)
int T, N, Q;
int arr[300001];
pair<long long int, bool> r[300001];
int main() {
    FASTIO;
    cin >> T;
    FOR(t, 0, T) {
        cin >> N >> Q;
        bool incre = 1;
        int pre = 0;
        int temp;
        long long int result = 0;
        FOR(i, 1, N+1) {
            cin >> arr[i];
            if (arr[i] > pre) {//증가
                if (!incre) {
                    incre = 1;
                    result -= pre;
                }
            }
            else if (arr[i] < pre) {//감소
                if (incre) {
                    incre = 0;
                    result += pre;
                }
            }
            r[i].first = result;
            r[i].second = incre;
            pre = arr[i];
        }
        if (incre)
            result += arr[N];
        cout << result << '\n';
        int left, right, m;
        FOR(q, 0, Q) {
            cin >> left >> right;
            m = arr[left];
            arr[left] = arr[right];
            arr[right] = m;
            bool incre = r[left - 1].second;
            int pre = arr[left - 1];
            long long int result = r[left-1].first;
            for (int x = left; x <=N; x++) {
                if (arr[x] > pre) {//증가
                    if (!incre) {
                        incre = 1;
                        result -= pre;
                    }
                }
                else if (arr[x] < pre) {//감소
                    if (incre) {
                        incre = 0;
                        result += pre;
                    }
                }
                r[x].first = result;
                r[x].second = incre;
                pre = arr[x];
            }
            if (incre)
                result += arr[N];
            cout << result << "\n";
        }
    }
    return 0;
}