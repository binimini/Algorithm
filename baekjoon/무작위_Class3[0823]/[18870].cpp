#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int N;
map<int, int> m;
int arr[1000000], sort_arr[1000000];
int main() {//좌표 압축
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        sort_arr[i] = arr[i];
    }
    sort(sort_arr, sort_arr + N);
    for (int i = 0; i < N; i++) {
        m.insert(make_pair(sort_arr[i], m.size()));
    }
    for (int i = 0; i < N; i++) {
        cout << m.find(arr[i])->second << ' ';
    }
    cout << '\n';
    return 0;
}