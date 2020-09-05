#include <iostream>
#include <stack>
using namespace std;
int N;
int dp[1000000], arr[1000000];
pair<int, int> result[1000000];
stack<int> s;
//재귀로 짜다가 포기 //예외케이스?
//lower_bound 사용하고 현재보다 큰값 기준으로 돌아가는 것까지는 맞.
int lower_bound(int end, int key) {
    int start = 0;
    int mid;
    while (end - start > 0) {
        mid = (start + end) / 2;
        if (dp[mid] < key) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
    return end;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    dp[0] = arr[0];
    result[0] = make_pair(0, arr[0]);
    int idx = 0;
    for (int i = 1; i < N; i++) {
        if (dp[idx] < arr[i]) {//크면 뒤에 추가
            idx++;
            dp[idx] = arr[i];
            result[i] = make_pair(idx, arr[i]);
        }
        else {//이미 idx 길이까지는 길어짐 길이 변화X
            //존재idx들 같거나 작은값으로 바꿔치기(크기순서 지켜서)
            //중간 값들만 바뀌면 정답 수열은 아니지만 길이는 같음 
            //가능성 //idx큰값이므로 건너뛰고 이어짐 가능
            int nidx = lower_bound(idx, arr[i]);
            dp[nidx] = arr[i];
            result[i] = make_pair(nidx, arr[i]);
        }
    }
    int temp = idx;
    for (int i = N - 1; i >= 0; i--) {
        if (idx == result[i].first) {//끝idx부터 돌아서 i작으면서 해당 idx에 들어갈수있는 값 
            s.push(result[i].second);
            idx--;
        }
    }
    cout << s.size() << "\n";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << '\n';
    return 0;
}