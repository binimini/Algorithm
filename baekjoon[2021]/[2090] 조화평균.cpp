#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
int N;
ll gcd(ll a, ll b) {
    ll temp;
    while (b) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

int main() {//한번에 lcm 구하고 분자 구하면 WA 45%
    cin >> N;
    ll num1 = 1, num2= 0;
    ll temp;
    for (int i = 0; i < N; i++) {
        ll c1, c2;
        cin >> temp;
        c2 = num2 * temp + num1;
        c1 = num1 * temp;
        ll g = gcd(c1, c2);
        num1 = c1 / g;
        num2 = c2 / g;
    }
    cout << num1 << "/" << num2 << "\n";
    return 0;
}