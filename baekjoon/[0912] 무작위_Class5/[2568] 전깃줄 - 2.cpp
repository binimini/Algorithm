#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int parent[500001] = { 0 };
bool visited[500001] = { 0 };
map<int, int> m;
vector<int> v;
int lower_bound(int key) {
    int s = 0, e = v.size();
    int mid;
    while (e - s > 0) {
        mid = (s + e) / 2;
        if (v[mid] < key)
            s = mid + 1;
        else
            e = mid;
    }
    return e;
}

int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int a, b;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        m.insert(make_pair(a, b));
    }
    for (map<int,int>::iterator i = m.begin(); i !=m.end(); i++) {//A 오름차순 증가순으로 보므로 B 작은 것이 best?
        if (v.empty())
            v.push_back(i->second);
        else if (v.back() < i->second) {
            v.push_back(i->second);
            parent[i->first] = v.size() - 1;
        }
        else {
            int t = lower_bound(i->second);
            v[t] = i->second;
            parent[i->first] = t;
        }
    }
    cout << N - v.size() << "\n";
    int idx = v.size() - 1;
    for (map<int,int>::reverse_iterator i = m.rbegin(); i !=m.rend(); i++) {
        if (parent[i->first] == idx) {
            visited[i->first] = 1;
            idx--;
        }
    }
    for (map<int, int>::iterator i = m.begin(); i != m.end(); i++) {
        if (visited[i->first]) continue;
        else cout << i->first << "\n";
    }
    
    return 0;
}