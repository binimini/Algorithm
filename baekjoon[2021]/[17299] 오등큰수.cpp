#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
vector<int> s, ans;
int N, F[1000001] = { 0 }, arr[1000001];
int main() {
    FASTIO;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        F[arr[i]]++;
    }
    for (int i = N - 1; i >= 0; i--) {
        while (!s.empty() && F[s.back()] <= F[arr[i]]) 
            s.pop_back();
        if (s.empty()) 
            ans.push_back(-1);
        else
            ans.push_back(s.back());
        s.push_back(arr[i]);
    }
    while (!ans.empty()) {
        cout << ans.back() << " ";
        ans.pop_back();
    }
    return 0;
}