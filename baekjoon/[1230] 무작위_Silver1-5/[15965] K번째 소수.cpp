#include <bits/stdc++.h>
using namespace std;
int N = 8000000, num;
bool arr[8000001] = { 0 };
int prime[500001];
int main() {
    cin >> num;
    for (int i = 2; i * i <= N; i++) {
        if (!arr[i]) {
            for (int j = i * 2; j <= N; j+=i) {
                arr[j] = 1;
            }
        }
    }
    int cnt = 1;
    for (int i = 2; i <= N; i++) {
        if (cnt > 500000)
            break;
        if (!arr[i]) {
            prime[cnt] = i;
            cnt++;
        }
    }
    cout << prime[num];
    return 0;
}