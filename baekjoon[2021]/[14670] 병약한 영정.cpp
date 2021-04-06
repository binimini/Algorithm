#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
int N, R, L;
map<int, int> m;
vector<int> v;
int main() {
    FASTIO;
    cin >> N;
    int symtom, medi_name;
    for (int i = 0; i < N; i++) {
        cin >> symtom >> medi_name;
        m[symtom] = medi_name;
    }
    cin >> R;
    int temp;
    bool dead_flag = 0;
    for (int i = 0; i < R; i++) {
        v.clear();
        dead_flag = 0;
        cin >> L;
        for (int j = 0; j < L; j++) {
            cin >> temp;
            if (m.find(temp) == m.end())
                dead_flag = 1;
            else
                v.push_back(m[temp]);
        }
        if (dead_flag)
            cout << "YOU DIED\n";
        else {
            for (int j = 0; j < v.size(); j++) {
                cout << v[j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}