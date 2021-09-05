#include <iostream>
using namespace std;
int N, K, cnt = 0;
bool notPrime[1001] = { 0 }; //notPrime[i] == false -> i 소수
int checkPrime() {
    for (int i = 2; i <= N; i++) {
        if (notPrime[i]) continue;
        if (++cnt==K) return i;
       
        for (int j = i*2; j <= N; j += i) {
            if (notPrime[j]) continue;
            
            if (++cnt == K) return j;
            notPrime[j] = true;
        }
    }
}
int main() {
    cin >> N >> K;

    cout << checkPrime();
    
    return 0;
}