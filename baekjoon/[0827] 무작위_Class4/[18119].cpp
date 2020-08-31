#include <iostream>
#include <vector>
using namespace std;
int N, M;
int memory = (1<<27) -1;
vector<int> v;
int main() {//단어 암기
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N >> M;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        int  temp = 0;
        for (int j = 0; j < s.size(); j++) {
            temp |= 1 << (s[j] - 'a');
        }
        v.push_back(temp);
    }
    int a;
    char b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        if (a == 1)
            memory &= ~(1 << (b - 'a'));
        else if (a == 2)
            memory |= 1 << (b - 'a');
        int cnt = 0;
        for (int j = 0; j < v.size(); j++) {
            if ((memory & v[j]) == v[j])
                cnt++;
        }
        cout << cnt << '\n';
    }
    return 0;
}
