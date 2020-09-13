#include <bits/stdc++.h>
using namespace std;
int N;
int visited[1000001] = { 0 };
int main() {
    cin >> N;
    int first;
    cin >> first;
    for (int i = 0; i < first; i++) {
        visited[i] = 1;
    }
    int temp;
    int min = first;
    for (int i = 1; i < N; i++) {
        cin >> temp;
        if (temp >= min) continue;
        else {
            for (int i = 0; i < min - temp; i++) {
                visited[(temp + i) % temp] += visited[temp + i];
            }
            min = temp;
        }
    }
    double result = 0.0;
    for (int i = 0; i < min; i++) {
        result += visited[i] * double(i)/first;
    }
    cout << fixed<< setprecision(10)<<result << "\n";
    return 0;
}