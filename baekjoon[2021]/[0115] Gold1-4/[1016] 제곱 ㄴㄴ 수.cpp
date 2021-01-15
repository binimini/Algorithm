#include <bits/stdc++.h>
using namespace std;
long long int min_num, max_num;
bool divided[1000001] = { 0 }, notprime[1000001] = { 0 };
int main() {//min-max 범위에서 제곱 수로 나눠지지않는 수
    //제곱수로 나눠지는 수 == 소수의 제곱수로 나눠지는 수 (모든 수 <- 소수의 곱 (자연수)^2*k = (소수*소수)^2*k)
    cin >> min_num >> max_num;//min 10^12 max min+10^6
    //제곱수 될 수 있는 수 최대 약 10^6
    int cnt = 0;//제곱수로 나눠지는 수 개수
    long long int max_sqrt = (long long)sqrt(max_num);
    for (int i = 2; i*i <= max_sqrt; i++) {//이 범위내에서 소수 판별 -> 에라토스테네스의 체
        //안해도 가능하지만 이 과정 거칠경우 10^6byte와 O(소수아닌제곱근수*그수의min-max내배수수) 줄일 수 있음
        if (!notprime[i]) {
            for (int j = i * 2; j <= max_sqrt; j += i) {
                notprime[j] = 1;
            }
        }
    }
    for (long long int i = 2; i <= max_sqrt; i++) {
        if (notprime[i]) continue;
        long long int div_min = min_num;
        if (div_min % (i*i) != 0) {
            div_min = (min_num / (i*i) + 1) * (i*i);
        }
        for (long long int j = div_min; j <= max_num; j += i*i) {
            if (!divided[j - min_num]) {
                divided[j - min_num] = true;
                cnt++;
            }
        }
    }
    cout << max_num - min_num + 1 - cnt;
    return 0;
}