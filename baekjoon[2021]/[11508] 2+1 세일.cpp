#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
int N;
vector<int> v;
int main() {
    FASTIO;
    cin >> N;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), greater<int>());//나중에 확인
    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        if ((i+1) % 3 == 0)
            continue;
        sum += v[i];
    }
    cout << sum;
    return 0;
}