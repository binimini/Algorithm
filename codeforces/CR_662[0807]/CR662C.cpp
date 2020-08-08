#include <bits/stdc++.h>
using namespace std;
int T, N, samecnt[100001] = { 0 };
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int i = 1; i <= 100000; i++) {
            samecnt[i] = 0;
        }
        int temp, M = 0;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            samecnt[temp]++;
        }
        int k = 0;
        for (int i = 1; i <= 100000; i++) {
            if (samecnt[i] > M) 
                M = samecnt[i], k = 1;
            else if (samecnt[i] == M) 
                k++;
        }
        if (M == 1)
            cout << N - 1 << "\n"; // 0으로 나눌 수 없음
        else if (N == M * k)
            cout << k - 1 << "\n"; // 0을 나눌 수 없음
        else cout << k-1+ (N-M*k)/(M-1)<< "\n"; //같은 개수의 수(자신 제외) +  같은 개수 아닌 수/ 나눠질 공간의 수
    }
    return 0;
}