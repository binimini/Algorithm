#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int T,M;
vector<int> res;
priority_queue<int> low, high;
int main() {
    FASTIO;
    cin >> T;
    for (int t = 0; t < T; t++) {
        int mid, temp;//초기화
        res.clear();
        while (!low.empty())
            low.pop();
        while (!high.empty())
            high.pop();

        cin >> M;
        cin >> mid;
        res.push_back(mid);//시작 중앙값은 자신
        for (int i = 2; i <= M; i++) {//시작값 따로 받으므로 2부터
            cin >> temp;
            if (temp > mid) {
                high.push(-temp);
            }
            else if (temp <= mid) {
                low.push(temp);
            }

            if ((int)high.size() - 2 >= (int)low.size()) {
                low.push(mid);
                mid = -high.top();
                high.pop();
            }
            else if ((int)low.size() - 2 >= (int)high.size()) {
                high.push(-mid);
                mid = low.top();
                low.pop();
            }

            if (i % 2 == 1)//홀수 차수에
                res.push_back(mid);
        }
        cout << M / 2 + 1 << "\n";
        for (int i = 0; i < res.size(); i++) {
            if (i!=0&&i % 10 == 0)//한 줄에 10개까지 i=0이면 무조건 0
                cout << "\n";
            cout << res[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}