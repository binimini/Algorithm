#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool compare(string a, string b) {
    if (a.size() == b.size()) {
        for (int i = 0; i < a.size(); i++) {
            if (a[i] != b[i])
                return a[i] < b[i];
        }
    }
    return a.size() < b.size();
}
int main() {
    int N;
    vector<string> v;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }
    sort(v.begin(), v.end(), compare);
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int j = 0; j < v.size(); j++) {
        cout << v[j] << '\n';
    }
    return 0;
}