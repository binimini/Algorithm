#include <iostream>
#include <set>
using namespace std;
int M;
set<int> s;
set<int> a;
int main() {//집합
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (int i = 1; i <= 20; i++) {
        a.insert(i);
    }
    cin >> M;
    string str;
    for (int i = 0; i < M; i++) {
        cin >> str;
        int temp;
        if (str == "all") {
            s = a;
            continue;
        }
        else if (str == "empty") {
            s.clear();
            continue;
        }
        cin >> temp;
        if (str == "add") {
            s.insert(temp);
        }
        else if (str == "remove") {
            set<int>::iterator iter = s.find(temp);
            if (iter == s.end()) continue;
            else if (iter != s.end())
                s.erase(iter);
        }
        else if (str == "check") {
            cout << s.count(temp) << "\n";
        }
        else if (str == "toggle") {
            set<int>::iterator iter = s.find(temp);
            if (iter == s.end())
                s.insert(temp);
            else if (iter != s.end())
                s.erase(iter);
        }
    }
    return 0;
}