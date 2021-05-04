#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int N, cnt, res = 0;
vector<int> v;
int main() {//가로 없애는 칸 vs 세로 없애는 칸 비교
    //배열 정렬 이용해서 idx 올려가며 arr[idx](가로)+ N-idx(세로) 중 최솟값
    FASTIO;
    cin >> N;
    cnt = N;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    while (cnt!=0) {
        res++;
        if (cnt > v.back()) {
            for (int i = 0; i < v.size(); i++) {
                if (v[i] == 1)
                    cnt--;
                v[i]--;
            }
        }
        else {
            cnt--;
            v.pop_back();
        }
    }
    cout << res;
    return 0;
}