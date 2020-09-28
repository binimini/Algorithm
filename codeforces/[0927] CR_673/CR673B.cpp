#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int arr[100000];
pair<int, int> sort_arr[100000];
int result[100000] = { 0 };
int t, N, T;
int main() {
    FASTIO;
    cin >> t;
    FOR(tt, 0, t) {
        cin >> N >> T;
        FOR(i, 0, N) {
            result[i] = -1;
            cin >> arr[i];
            sort_arr[i] = { arr[i], i };
        }
        sort(sort_arr, sort_arr + N);
        int s = 0, e = N - 1;
        bool flag = 1;
        while (e - s >= 0) {
            if (s == e) {
                result[sort_arr[s].second] = 1;
                break;
            }
            if (sort_arr[s].first + sort_arr[e].first == T) {
                if (T % 2 == 0 && sort_arr[s].first == T / 2) {
                    if (result[sort_arr[s].second] != -1) {
                        result[sort_arr[e].second] = flag;
                        flag = !flag;
                    }
                    else
                        result[sort_arr[s].second] = 1, result[sort_arr[e].second] = 0;
                }
                else {
                    if (result[sort_arr[s].second] != -1)
                        result[sort_arr[e].second] = 1 - result[sort_arr[s].second];
                    else
                        result[sort_arr[s].second] = 1, result[sort_arr[e].second] = 0;
                }
                e--;
            }
            else if (sort_arr[s].first + sort_arr[e].first < T) {
                result[sort_arr[s].second] = 1;
                s++;
            }
            else if (sort_arr[s].first + sort_arr[e].first > T) {
                result[sort_arr[e].second] = 1;
                e--;
            }
        }
        FOR(i, 0, N) {
            cout << result[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}