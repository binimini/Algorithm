#include <bits/stdc++.h>
using namespace std;
int N, arr[200];
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<int> LIS;
int lowerbound(int k) {
    int s = 0, e = LIS.size(), m;
    while (e - s > 0) {
        m = (s + e) / 2;
        if (LIS[m] >= k)
            e = m;
        else if (LIS[m] < k) 
            s = m + 1;
    }
    return e;
}
int main() {
    cin >> N;
    FASTIO;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < N; i++) {
        if (LIS.empty())
            LIS.push_back(arr[i]);
        else {
            if (LIS.back() < arr[i])
                LIS.push_back(arr[i]);
            else
                LIS[lowerbound(arr[i])] = arr[i];
        }
    }
    cout << N - LIS.size();
    return 0;
}