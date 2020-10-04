#include <iostream>
#include <vector>
using namespace std;
int N;
vector<int> seq;
int  lb(int k) {
    int s = 0, e = seq.size();
    int m;
    while (e - s > 0) {
        m = (s + e) / 2;
        if (seq[m] < k)
            s = m + 1;
        else
            e = m;
    }
    return e;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (seq.empty())
            seq.push_back(temp);
        else {
            if (temp > seq.back())
                seq.push_back(temp);
            else {
                seq[lb(temp)] = temp;
            }
        }
    }
    cout << seq.size() << "\n";
    return 0;
}