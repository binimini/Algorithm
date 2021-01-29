#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N;
bool notprime[1000001] = { 0 };
int main() {
    FASTIO;
    notprime[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        if (notprime[i]) continue;
        for (int j = i*2; j <= 1000000; j += i) {
            notprime[j] = 1;
        }
    }
    while (1) {
        bool found = 0;
        cin >> N;
        if (N == 0)
            break;
        for (int i = 2; i < N; i++) {
            if (!notprime[i] && !notprime[N - i]) {
                cout <<N<<" = "<< min(i, N - i) << " + " << max(i, N - i) << "\n";
                found = 1;
                break;
            }
        }
        if (!found)
            cout << "Goldbach's conjecture is wrong." << "\n";
    }
    return 0;
}