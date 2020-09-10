#include <iostream>
#include <tuple>
#include <algorithm>
using namespace std;
int N, INF = 2000000001;
int arr[100000];
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
    
    tuple<int, int, int> result = { INF, 0, 0 };
    for (int i = 0; i < N; i++) {
        int idx = lower_bound(-arr[i]);
        tuple<int, int, int> temp1 = { INF,0,0 }, temp2 = { INF,0,0 }, r = { INF,0,0 };
        
        if (idx == i) {
            if (idx + 1 < N) {
                get<0>(temp1) = arr[idx + 1] + arr[i];
                get<1>(temp1) = min(idx + 1, i);
                get<2>(temp1) = max(idx + 1, i);
            }
            if (idx - 1 >= 0) {
                get<0>(temp2) = arr[idx - 1] + arr[i];
                get<1>(temp2) = min(idx - 1, i);
                get<2>(temp2) = max(idx - 1, i);
            }
        }
        
        else {
            if (idx - 1 >= 0) {
                if (idx - 1 != i) {
                    get<0>(temp2) = arr[idx - 1] + arr[i];
                    get<1>(temp2) = min(idx - 1, i);
                    get<2>(temp2) = max(idx - 1, i);
                }
                else {
                    get<0>(temp2) = arr[idx - 2] + arr[i];
                    get<1>(temp2) = min(idx - 2, i);
                    get<2>(temp2) = max(idx - 2, i);
                }
            }
            if (idx < N) {
                get<0>(temp1) = arr[idx] + arr[i];
                get<1>(temp1) = min(idx, i);
                get<2>(temp1) = max(idx, i);
            }
        }
        
        if (abs(get<0>(temp1)) < abs(get<0>(temp2)))
            r = temp1;
        else
            r = temp2;
        if (abs(get<0>(result)) > abs(get<0>(r)))
            result = r;
    }
    
    cout << arr[get<1>(result)] << " " << arr[get<2>(result)] << "\n";
    return 0;
}