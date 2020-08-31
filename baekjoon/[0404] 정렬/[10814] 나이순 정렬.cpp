#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;
bool compare(pair<int, string> a, pair<int, string> b) {
    return a.first < b.first;
}
int main() {
    int N;
    cin >> N;
    vector<pair<int, string>> v;
    for (int i = 0; i < N; i++) {
        int age;
        string name;
        cin >> age >> name;
        v.push_back(make_pair(age, name));
    }
    stable_sort(v.begin(), v.end(), compare);
    for (int j = 0; j < N; j++) {
        cout << v[j].first << " " << v[j].second << '\n';
    }
    return 0;
}