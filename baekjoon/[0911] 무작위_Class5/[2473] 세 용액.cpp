#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int N;
long long int INF = 3000000001;//int 범위 초과 
int arr[5000];
int lower_bound(int key) {
    int s = 0, e = N;
    int m;
    while (e - s > 0) {
        m = (s + e) / 2;
        if (arr[m] < key) {
            s = m + 1;
        }
        else e = m;
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

    long long int temp1[4], temp2[4], r[4], result[4];//최대 10억+10억+10억 long long
    result[0] = INF;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            int idx = lower_bound(-(arr[i]+arr[j]));//두 개 합 벡터에 넣고 나열하게되면 int[25000000] 메모리 부족

            temp1[0] = INF;
            temp2[0] = INF;
            r[0] = INF;

            int temp = idx;
            while (!(temp != i && temp != j) && temp < N) {
                temp++;
            }
            if (temp != N) {
                temp1[0] = arr[temp];
                temp1[0] += arr[i];
                temp1[0] += arr[j];
                temp1[1] = temp;
                temp1[2] = i;
                temp1[3] = j;
            }
            temp = idx - 1;
            while (!(temp != i && temp != j ) && temp >= 0) {
                temp--;
            }
            if (temp >= 0) {
                temp2[0] = arr[temp];
                temp2[0] += arr[i];
                temp2[0] += arr[j];
                temp2[1] = temp;
                temp2[2] = i;
                temp2[3] = j;
            }

            if (abs(temp1[0]) < abs(temp2[0])) {
                r[0] = temp1[0];
                r[1] = temp1[1];
                r[2] = temp1[2];
                r[3] = temp1[3];
            }
            else {
                r[0] = temp2[0];
                r[1] = temp2[1];
                r[2] = temp2[2];
                r[3] = temp2[3];
            }
            if (abs(result[0]) > abs(r[0])) {
                result[0] = r[0];
                result[1] = arr[r[1]];
                result[2] = arr[r[2]];
                result[3] = arr[r[3]];
            }
        }
    }
    sort(result + 1, result + 4);
    for (int i = 1; i <= 3; i++) {
        cout << result[i] << " ";
    }
    cout << "\n";
    return 0;
}