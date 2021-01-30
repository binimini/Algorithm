#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long int ll;
ll dp[1 << 15][101];//[bit][mod] //15! -> long long int range
int N, K, lenofnum[15], arr[15] = { 0 }, ten[51];
string str[15];

ll GCD(ll a, ll b) {//greatest common divisor (a>=b)
    ll temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

ll solve(int bit, int mod) {
    if (bit == ((1 << N) - 1)) {//all use
        if (mod == 0)//divided by K
            return 1;
        else
            return 0;
    }
    if (dp[bit][mod] != -1)
        return dp[bit][mod];

    ll& r = dp[bit][mod];
    r = 0;//init
    for (int i = 0; i < N; i++) {
        if (bit & (1 << i)) continue;//already used
        //number = {A + B} = A*10^len(B)+B
        //new mod =  ( (beforemod*10^len(B))%K + B%K )%K
        r += solve(bit | (1 << i), ((mod * ten[lenofnum[i]]) % K + arr[i] % K) % K);
    }
    return r;
}
int main() {
    FASTIO;
    cin >> N;
    for (int i = 0; i < N; i++) {//input
        cin >> str[i];
        lenofnum[i] = str[i].size();
    }
    cin >> K;

    ten[0] = 1 % K;//pow(10,i) -> long long int range overflow //ten[i] = pow(10,i)%K
    for (int i = 1; i <= 50; i++) {
        ten[i] = (ten[i - 1] * 10) % K;
    }
    for (int i = 0; i < 15; i++) {//stoi int range ll out of range
        for (int j = 0; j < lenofnum[i]; j++) {//number save as moduler
            arr[i] = (arr[i] * 10 + (str[i][j] - '0')) % K;// 5%4 = 1  54%4 = (1*10+4)%4 = 2
        }
    }

    memset(dp, -1, sizeof(dp));
    ll p, q = 1, r;
    for (int i = 2; i <= N; i++) {//N factorial
        q *= i;
    }
    p = solve(0, 0);
    r = GCD(q, p);//Irreducible fraction -> p and q is divided by r = GCD(q,p)(q>=p)
    q /= r;
    p /= r;
    cout << p << "/" << q;
    
    return 0;
}