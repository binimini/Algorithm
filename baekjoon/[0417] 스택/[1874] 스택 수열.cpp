#include <iostream>
#include <vector>
using namespace std;
int N, cont = 0;
vector<int> v;
vector<char> x;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        while (cont < temp) {
            cont++;
            v.push_back(cont);
            x.push_back('+');
        }
        if (cont == temp) {
            v.pop_back();
            x.push_back('-');
        }
        if (cont > temp) {
            if (v.empty() == 1)
                break;
            if (v.back() == temp) {
                v.pop_back();
                x.push_back('-');
            }
        }
    }
    if (v.empty() == 1) {
        for (int i = 0; i < x.size(); i++) {
            cout << x[i] << "\n";
        }
    }
    else {
        cout << "NO" << '\n';
    }
    return 0;
}