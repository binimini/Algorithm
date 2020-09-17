#include <bits/stdc++.h>
using namespace std;
//100011100001101111001001101111110000010000000000000000
long long int calcu(long long int N) {
    long long int sum = (N + 1) / 2;
    int i = 1;
    long long int cnt = (long long int)(powl(2, i));
    while (N >= cnt) {
        if (cnt == N) {
            sum++;
            break;
        }
        long long int NN = N - (long long int)(powl(2, i));
        if ((NN / cnt) % 2 != 0) {//홀수 몫
            sum +=(((NN / cnt) - 1) / 2)* cnt + cnt;
        }
        else {//짝수 몫
            if (NN / cnt != 0)
                sum += ((NN / cnt) / 2) * cnt + NN % ((NN / cnt) * cnt) + 1;
            else
                sum += NN + 1;
        }
        i++;
        cnt = (long long int)(powl(2, i));
    }
    return sum;
}
int main() {
    long long int A, B;
    cin >> A >> B;
    long long int result = calcu(B) - calcu(A-1);
    cout << result << "\n";
    return 0;
}