#include <bits/stdc++.h>
using namespace std;
long long int N;
long long int solve(long long int N) {
    long long int k = 2, ans = 1;
    vector<pair<long long int,long long int>> v;
    int cnt = 0;
    while (k * k <= N) {
        cnt = 0;
        while (N % k == 0) {
            cnt++;
            N /= k;
        }
        if (cnt != 0) {
            v.push_back(make_pair(k, cnt));
        }
        k++;
    }
    if (N != 1) {//root(N)<prime is exist!!(one or not exist)
        //(one or not exist //prime a*prime b(a,b>root(N)) => bigger than N (impossible)
        v.push_back(make_pair(N, 1));
    }
    for (int i = 0; i < v.size(); i++) {
        ans *= (v[i].first - 1)*(long long int)pow(v[i].first, v[i].second - 1);
    }
    return ans;
}
int main() {
    cin >> N;//Euler's totient function
    //N = p1^a1*p2^a2*... (prime p) -> number of k (GCD(N,K) = 1) : (p1-1)p1^(a1-1)*(p2-1)p2^(a2-1)...
    //N (maximum 10^12) prime factorization in O(root(N))!!
    cout << solve(N);

}