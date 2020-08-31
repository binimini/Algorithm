#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> result;
int L, C, arr[16];
bool visited[16] = { 0 };
char ch[16];
void DFS(int node, int cnt) {
    if (cnt == L) {
        string s = "";
        int a_cnt = 0, b_cnt = 0;
        for (int i = 0; i < cnt; i++) {
            if (ch[arr[i]] == 'a' || ch[arr[i]] == 'e' || ch[arr[i]] == 'i' || ch[arr[i]] == 'o' || ch[arr[i]] == 'u')
                a_cnt++;
            else b_cnt++;
            s += "0";
        }
        
        if (!(a_cnt >= 1 && b_cnt >= 2)) return;
        result.push_back(s);
        for (int i = 0; i < cnt; i++) {
            result[result.size()-1][i] =  ch[arr[i]];
        }
        return;
    }
    for (int i = node; i < C; i++) {
        arr[cnt] = i;
        DFS(i+1, cnt + 1);
    }
}
int main() {//암호 만들기
    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        cin >> ch[i];
    }
    sort(ch, ch + C);
    DFS(0, 0);
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << "\n";
    }
    return 0;
}