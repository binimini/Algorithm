#include <bits/stdc++.h>
using namespace std;
vector<int> digit;
int K;
string res = "";
int lowerbound() {
    int s = 0, e = digit.size(), m;
    while (e - s > 0) {
        m = (s + e) / 2;
        if (digit[m] >= K)
            e = m;
        else
            s = m + 1;
    }
    return e;
}
int main() {
    cin >> K;
    digit.push_back(0);
    int sum = 0, i = 0;
    while (sum <= 1000000000) {
        i++;
        sum += (int)pow(2, i);
        digit.push_back(sum);
    }
    int n = lowerbound(), k = K - digit[n - 1];
    while (n>0) {
        int temp =(int)pow(2, n);
        if (k > temp / 2) {
            res += "7";
            k -= (int)pow(2, n - 1);
        }
        else
            res += "4";
        n--;
    }
    cout << res;
    return 0;
}