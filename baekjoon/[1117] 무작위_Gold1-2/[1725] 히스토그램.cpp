#include <bits/stdc++.h>
using namespace std;
int N,tree[400001], arr[100000];
int init(int node, int start, int end) {
    if (start == end)
        return tree[node] = start;
    int mid = (start + end) / 2;
    int temp1 = init(node * 2, start, mid);
    int temp2 = init(node * 2 + 1, mid + 1, end);
    if (arr[temp1] < arr[temp2])
        return tree[node] = temp1;
    else
        return tree[node] = temp2;
}
int h(int node, int start, int end, int left, int right) {//가장 공통(낮은) 높이 인덱스
    if (left>end||start>right)
        return -1;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    int temp1 = h(node * 2, start, mid, left, right);
    int temp2 = h(node * 2 + 1, mid + 1, end, left, right);
    if (temp1 == -1)
        return temp2;
    if (temp2 == -1)
        return temp1;
    if (arr[temp1] < arr[temp2])
        return temp1;
    else
        return temp2;
}
int solve(int left, int right) {//공통 높이 기준으로 양옆으로 나눠서 넓이 최대 확인
    int idx = h(1, 0, N - 1, left, right);
    int area = arr[idx] * (right - left + 1);
    if (idx != left)
        area = max(area, solve(left, idx - 1));
    if (idx != right)
        area = max(area, solve(idx + 1, right));
    return area;
}
int main() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    init(1, 0, N - 1);
    cout << solve(0, N - 1);
    return 0;
}