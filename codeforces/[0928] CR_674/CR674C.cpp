#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define FOR(i,a,b) for (int i = a; i<b; i++)
int T, N, INF = 1000000000;
int main() {
    cin >> T;
    FOR(t, 0, T) {
        cin >> N;
        int x = 1;
        while (1) {
            int temp1, temp2;
            if (x == N)
                break;
            if (N % x == 0)
                temp1 = N / x;
            else
                temp1 = N / x + 1;
            if (N % (x+1) == 0)
                temp2 = N / (x+1);
            else
                temp2 = N / (x+1) + 1;
            if (temp1 > temp2) {
                x++;
            }
            else
                break;
        }
        if(N%x==0)
            cout << N / x + x - 2 << "\n";
        else
            cout << N / x + x - 1 << "\n";
    }
    return 0;
}