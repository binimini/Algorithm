#include <bits/stdc++.h>
using namespace std;
int N, res = 0;//dp [prime idx][prime sum] maximum 3*10^5*4*10^6 =12*10^11??
vector<int> v;
bool notprime[4000001] = { 0 };
int main() {
    cin >> N;
    for (int i = 2; i * i <= N; i++) {
        if (!notprime[i]) {
            for (int j = i*2; j <= N; j += i) {
                notprime[j] = 1;
            }
        }
    }
    for (int i = 2; i <= N; i++) {//4000000 prime size about 300000
        if (!notprime[i])
            v.push_back(i);
    }
    int s = 0, e = 0, sum = 0;
    while (e<=v.size()) {//two pointer
        if (sum < N) {
            if (e == v.size())//exception (outbound RTE)
                break;
            sum += v[e];
            e++;
        }
        else if (sum >= N) {
            sum -= v[s];
            s++;
        }
        if (sum == N)
            res++;
    }
    cout << res;
    return 0;
}