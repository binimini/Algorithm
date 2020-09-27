#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FOR(i,a,b) for(int i = a; i<b; i++)
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
int N, H;
vector<int> l;
vector<int> u;
int lower_bound(int key) {
    int s = 0, e = l.size(), m;
    while (e - s > 0) {
        m = (s + e) / 2;
        if (key > l[m])
            s = m + 1;
        else
            e = m;
    }
    return e;
}
int upper_bound(int key) {
    int s = 0, e = u.size(), m;
    while (e - s > 0) {
        m = (s + e) / 2;
        if (key >= u[m])
            s = m + 1;
        else
            e = m;
    }
    return e;
}
int main() {
    FASTIO;
    cin >> N >> H;
    int temp;
    FOR(i, 0, N) {
        cin >> temp;
        if (i % 2 == 0)
            u.push_back(temp);
        else
            l.push_back(temp);
    }
    sort(l.begin(), l.end());
    sort(u.begin(), u.end());
    pair<int, int> mini = { 200001, 0 };
    int sum;
    FOR(i, 1, H + 1) {
        sum = 0;
        sum += l.size() - lower_bound(i);
        sum += u.size()- upper_bound(H-i);
        if (mini.first >= sum) {
            if (mini.first == sum)
                mini.second++;
            else {
                mini.first = sum;
                mini.second = 1;
            }
        }
    }
    cout << mini.first << " " << mini.second << "\n";
    return 0;
}