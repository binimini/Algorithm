#include <iostream>
#include <algorithm>
using namespace std;
int N, arr[100000], tree[400001];
void init(int node, int start, int end) {
    if (start == end) {
        tree[node] = start;
        return;
    }
    int mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    if (arr[tree[node * 2]] < arr[tree[node * 2 + 1]])
        tree[node] = tree[node * 2];
    else tree[node] = tree[node * 2 + 1];
}
int query(int node, int start, int end, int left, int right) {
    if (left > end || right < start)
        return -1;
    if (left <= start && end <= right)
        return tree[node];
    int mid = (start + end) / 2;
    int temp1 = query(node * 2, start, mid, left, right);
    int temp2 = query(node * 2 + 1, mid + 1, end, left, right);
    if (temp1 == -1)
        return temp2;
    else if (temp2 == -1)
        return temp1;
    else {
        if (arr[temp1] < arr[temp2])
            return temp1;
        else return temp2;
    }
}
long long int getMax(int start, int end) {
    int m = query(1, 0, N - 1, start, end);
    int size = end - start + 1;
    long long int area = arr[m];
    area = area * size;
    if (start <= m - 1) {
        long long int temp1 = getMax(start, m - 1);
        if (area < temp1)
            area = temp1;
    }
    if (m + 1 <= end) {
        long long int temp2 = getMax(m + 1, end);
        if (area < temp2)
            area = temp2;
    }
    return area;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (1) {
        cin >> N;
        if (!N) break;
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        init(1, 0, N - 1);
        cout << getMax(0, N - 1) << "\n";
    }
    return 0;
}