#include <iostream>
#include <algorithm> //max(), min()
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N;
int GCD(int m, int n) { //GCD(m,n)==GCD(n, m%n)
    int mod;
    while(n) {
        mod = m % n;
        m = n;
        n = mod;
    }
    
    return m;
}
int main() {
    cin >> N; 
    int a, b, gcd, lcm;
    for (int n = 0; n < N; n++) {
        cin >> a >> b;
        
        gcd = GCD(max(a, b), min(a, b));
        lcm = a * b / gcd;
        
        cout << lcm << "\n";
    }
    return 0;
}