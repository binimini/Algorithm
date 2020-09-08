#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i<b; i++)
#define FASTIO std::ios_base::sync_with_stdio(0); cin.tie(0);
int T, N, M, cnt = 0;
int A[1000], B[1000];
vector<int> SoA, SoB;
int upper_bound(int key) {
    int s = 0, e = SoB.size(); //들어온 값이 가장 클 때 최대인덱스+1 반환
    int m;
    while (e - s > 0) {//e 최대인덱스+1이므로 s==e이면 없는 인덱스에 접근하게됨
        m = (s + e) / 2;
        if (SoB[m] <= key) {
            s = m + 1;
        }
        else
            e = m;
    }
    return e;
}
int lower_bound(int key) {
    int s = 0, e = SoB.size();
    int m;
    while (e - s > 0) {
        m = (s + e) / 2;
        if (SoB[m] < key) {
            s = m + 1;
        }
        else
            e = m;
    }
    return e;
}
int main() {
    cin >> T;
    cin >> N;
    int sum = 0;
    FOR(i, 0, N) {
        cin >> A[i];
        sum += A[i];
        A[i] = sum;
    }
    cin >> M;
    sum = 0;
    FOR(i, 0, M) {
        cin >> B[i];
        sum += B[i];
        B[i] = sum;
    }
    FOR(i, 0, N) {
        FOR(j, i, N) {
            if (i != 0)
                SoA.push_back(A[j] - A[i - 1]);
            else SoA.push_back(A[j]);
        }
    }
    FOR(i, 0, M) {
        FOR(j, i, M) {
            if (i != 0)
                SoB.push_back(B[j] - B[i - 1]);
            else SoB.push_back(B[j]);
        }
    }
    sort(SoB.begin(), SoB.end());
    long long int cnt = 0;
    for (int i = 0; i < SoA.size(); i++) {
        int temp1 = upper_bound(T - SoA[i]);
        int temp2 = lower_bound(T - SoA[i]);
        cnt += temp1;
        cnt -=temp2;
    }
    cout << cnt << '\n';
    return 0;
}