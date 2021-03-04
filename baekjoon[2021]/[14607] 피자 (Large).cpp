#include <bits/stdc++.h>
using namespace std;
long long int N;
int main() {
    cin >> N;
    //result(N+1) : result(N) + 0(1) + N*1 
    //== result + N // sum of 1~N
    cout << (N - 1) * N / 2;
    return 0;
}