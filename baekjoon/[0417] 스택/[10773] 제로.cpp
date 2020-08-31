#include <iostream>
#include <vector>
using namespace std;
int K, sum = 0;
vector<int> v;
int main() {
    cin.tie(NULL);
    cin >> K;
    for (int i = 0; i < K; i++) {
        int temp;
        cin >> temp;
        if (temp == 0)
            v.pop_back();
        else {
            v.push_back(temp);
        }
    }
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
    }
    cout << sum << "\n";
    return 0;
}