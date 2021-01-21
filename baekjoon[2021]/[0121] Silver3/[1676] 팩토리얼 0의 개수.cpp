#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    cin >> N;
    //number of 0 == number of (5*2) == min(countof5,countof2) for factorial N
    int cnt_2 = 0, cnt_5 = 0;
    int i = 1, temp; 
    while (i <= N) {//can't solve with factorization?
        temp = i;
        while (temp % 2 == 0) {
            temp /= 2;
            cnt_2++;
        }

        while (temp % 5 == 0) {
            temp /= 5;
            cnt_5++;
        }
        i++;
    }
    cout << min(cnt_2, cnt_5);
    return 0;
}