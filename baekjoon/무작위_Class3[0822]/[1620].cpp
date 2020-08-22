#include <iostream>
#include <map>
#include <string>
using namespace std;
int N, M;
string arr[100001];
map<string, int> m;
int main() {//나는야 포켓몬 마스터 이다솜
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    string temp;
    for (int i = 1; i <= N; i++) {
        cin >> temp;
        arr[i] = temp;
        m.insert(make_pair(temp, i));
    }
    for (int i = 0; i < M; i++) {
        cin >> temp;
        if (temp[0] < 65) {
            cout << arr[stoi(temp)] << "\n";
        }
        else {
            cout << m.find(temp)->second <<'\n';
        }
    }
    return 0;
}