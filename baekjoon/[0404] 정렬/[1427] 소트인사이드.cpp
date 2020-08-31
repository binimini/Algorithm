#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    string s;
    vector <int> v;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        v.push_back(s[i] - '0');
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    return 0;
}