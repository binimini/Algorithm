#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> v;
int lb(int key) {
    int s = 0, e = v.size();
    int m;
    while (e - s > 0) {
        m = (e + s) / 2;
        if (v[m] < key)
            s = m + 1;
        else
            e = m;
    }
    return e;
}
int main() {
    std::ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (v.empty())
            v.push_back(temp);
        else {
            if (v.back() < temp) 
                v.push_back(temp);
            else {
                v[lb(temp)] = temp;
            }
        }
    }
    cout << v.size();
    return 0;
}