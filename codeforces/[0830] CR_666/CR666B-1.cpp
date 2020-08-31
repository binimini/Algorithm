#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int N, arr[100000];
int main() {
    FASTIO;
    cin >> N;
    long long int result = 0;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        result += arr[i];
    }
    result -= N;
    sort(arr, arr + N);
    pair<int, int> m = { 1000000001, 0 };
    for (int i = 1; i <= 100000; i++) {
        if (m.first > abs(arr[N - 1] - int(pow(i, N - 1)))) {
            m.first = abs(arr[N - 1] - int(pow(i, N - 1)));
            m.second = i;
       }
    }
    int s[3];
    s[0] = m.second - 1;
    s[1] = m.second;
    s[2] = m.second + 1;
    for (int i = 0; i < 3; i++) {
        long long int temp = 0;
        for (int j = 0; j < N; j++) {
            long long int t = arr[j];
            t -= int(pow(s[i], j));
            if (t < 0)
                t *= -1;
            temp += t;
        }
        result = min(temp, result);
    }
    cout << result << "\n";
    return 0;
}