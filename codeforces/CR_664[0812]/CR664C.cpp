#include <bits/stdc++.h>
using namespace std;
int N, M;
int a[200], b[200];
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }
    int mmm_result = 513;
    int m_result = 0;
    int result = 0;
    for (int x = 0; x < M; x++) {
        m_result = a[0] & b[x];
        for (int i = 1; i < N; i++) {
            int m_a = 513;
            int mm_result = 513;
            for (int j = 0; j < M; j++) {
                result = m_result;
                result |= a[i] & b[j];
                mm_result = min(mm_result, result);
            }
            m_result = mm_result;
        }
        mmm_result = min(m_result, mmm_result);
    }
    cout << mmm_result << '\n';
    return 0;
}