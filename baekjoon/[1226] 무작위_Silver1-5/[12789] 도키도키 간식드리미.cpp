#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
    vector<int> v;
    cin >> N;
    int order = 1, temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        while (!v.empty() && v.back() == order) {
            v.pop_back();
            order++;
        }
        if (temp == order)
            order++;
        else
            v.push_back(temp);
    }
    while (!v.empty() && v.back() == order) {
        v.pop_back();
        order++;
    }
    if (!v.empty())
        cout << "Sad";
    else
        cout << "Nice";
    return 0;
}