#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int A[4000], B[4000], C[4000], D[4000];
vector<int> X, Y;
int lower_bound(int key) {
    int start = 0;
    int end = Y.size();
    int mid = Y.size();
    while (end - start > 0) {
        mid = (start + end) / 2;
        if (Y[mid] < key)
            start = mid + 1;
        if (Y[mid] >= key)
            end = mid;
    }
    return end;
}
int upper_bound(int key) {
    int start = 0;
    int end = Y.size();
    int mid = Y.size();
    while (end - start > 0) {
        mid = (start + end) / 2;
        if (Y[mid] <= key)
            start = mid + 1;
        if (Y[mid] > key)
            end = mid;
    }
    return end;

}
int main() {//합이 0인 네 정수
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Y.push_back(C[i] + D[j]);
        }
    }
    sort(Y.begin(), Y.end());
    long long int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            result += upper_bound(-(A[i] + B[j]));
            result -= lower_bound(-(A[i] + B[j]));
        }
    }
    cout << result << "\n";
    return 0;
}