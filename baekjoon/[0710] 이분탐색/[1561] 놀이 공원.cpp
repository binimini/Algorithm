#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int M, info[10001], R = 31;
long long int N;
int binary_search(long long int left, long long int right) {
    long long int mid;
    while (right - left >= 0) {
        mid = (right + left) / 2;
        vector<int> v;
        long long int sum = M;
        for (int i = 1; i <= M; i++) {
            if (mid % info[i] == 0)
                v.push_back(i);
            sum += mid / info[i];
        }
        if (sum - v.size() < N && N <= sum) {
            return v[N - sum + v.size() - 1];
        }
        else if (sum - v.size() >= N)
            right = mid - 1;
        else if (sum < N)
            left = mid + 1;
    }
}
int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> info[i];
        R = min(info[i], R);
    }
    cout << binary_search(0, R * N);
    return 0;
}