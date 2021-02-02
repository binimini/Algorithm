#include <bits/stdc++.h>
using namespace std;
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
deque<pair<int,int>> dq;
int N, L;
int main() {
    FASTIO;
    //슬라이딩 윈도우 (최솟값) O(N)
    //1. deq 최대 L개의 숫자
    //2. 오름차순 정렬(최솟값 바로 접근 가능), i번째에서 최대 큰 값 == arr[i]
    cin >> N >> L;
    int temp, idx = 0;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        if (!dq.empty() && dq.front().second <= i - L)//한 턴에서 나가는 건 최대 한개
            dq.pop_front();
        while (!dq.empty() && dq.back().first > temp)// arr[i]보다 크면서 이미 존재하는 건 여러개 가능
            dq.pop_back();
        dq.push_back({ temp,i });
        cout << dq.front().first << " ";
    }
    cout << "\n";
    return 0;
}