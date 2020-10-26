#include <iostream>
#include <vector>
using namespace std;
int N;
int arr[1000], result[1000];
vector<int> v;
int lb(int k) {
    int s = 0, e = v.size(), m;
    while (e - s > 0) {
        m = (s + e) / 2;
        if (v[m] < k)
            s = m + 1;
        else
            e = m;
    }
    return e;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        if (v.empty()) {
            result[i] = v.size();
            v.push_back(arr[i]);
        }
        else if (v.back() < arr[i]) {
            result[i] = v.size();
            v.push_back(arr[i]);
        }
        else {
            int idx = lb(arr[i]);
            v[idx] = arr[i];
            result[i] = idx;
        }
    }
    cout << v.size() << "\n";
    int cnt = v.size() - 1;
    vector<int> r;
    for (int i = N - 1; i >= 0; i--) {
        if (result[i] == cnt) {
            r.push_back(arr[i]);
            cnt--;
        }
    }
    while (!r.empty()) {
        cout << r.back() << " ";
        r.pop_back();
    }
    cout << '\n';
    return 0;
}