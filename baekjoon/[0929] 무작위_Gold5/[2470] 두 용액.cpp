#include <iostream>
#include <tuple>
#include <algorithm>
#include <math.h>
using namespace std;
int N, arr[100000];
int lb(int k) {
    int s = 0, e = N;
    int m;
    while (e - s > 0) {
        m = (s + e) / 2;
        if (k > arr[m])
            s = m + 1;
        else
            e = m;
    }
    return e;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    tuple<int, int, int> result = { 2000000001, 0,0 };
    tuple<int, int, int> tocomp = { 2000000001, 0,0 };
    for (int i = 0; i < N; i++) {
        int LB = lb(-arr[i]);
        int temp = LB;
        while (!(temp != i) && temp < N) {
            temp++;
        }
        if (temp != N) {
            get<0>(tocomp) = abs(arr[temp] + arr[i]);
            get<1>(tocomp) = min(temp,i);
            get<2>(tocomp) = max(temp,i);
        }
        temp = LB - 1;
        while (!(temp != i) && temp >= 0) {
            temp--;
        }
        if (temp >= 0) {
            if (abs(arr[temp] + arr[i]) < get<0>(tocomp)) {
                get<0>(tocomp) = abs(arr[temp] + arr[i]);
                get<1>(tocomp) = min(temp, i);
                get<2>(tocomp) = max(temp, i);
            }
        }
        if (get<0>(tocomp) < get<0>(result)) {
            get<0>(result) = get<0>(tocomp);
            get<1>(result) = get<1>(tocomp);
            get<2>(result) = get<2>(tocomp);
        }
    }
    cout << arr[get<1>(result)] << " " << arr[get<2>(result)] << "\n";
    return 0;
}