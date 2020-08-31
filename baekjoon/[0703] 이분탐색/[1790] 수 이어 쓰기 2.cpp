#include <iostream>
#include <math.h>
using namespace std;
int N, k, temp = 0;
int len_of_n(int n) {
    int c_n = n, len = 0;
    temp = 0;
    while (c_n > 0) {
        if (c_n >= 10) {
            c_n = c_n / 10;
            len += (temp + 1) * 9 * int(pow(10, temp));
            temp++;
        }
        else {
            len += (n - int(pow(10, temp)) + 1) * (temp + 1);
            return len;
        }
    }
}
int binary_search(int N, int key) {
    int start = 1;
    int end = N;
    int mid;
    while (end - start >= 0) {
        mid = (start + end) / 2;
        int len = len_of_n(mid);
        if (len - temp <= key && key <= len) {
            int key_k = temp - (key - (len - temp + 1));
            return (mid % int(pow(10, key_k))) / int(pow(10, key_k - 1));
        }
        else if (key > len) {
            start = mid + 1;
        }
        else if (key < len - temp) {
            end = mid - 1;
        }
    }
}
int main() {
    cin >> N >> k;
    int len = len_of_n(N);
    if (len < k) {
        cout << -1;
    }
    else {
        cout << binary_search(N, k);
    }
    return 0;
}