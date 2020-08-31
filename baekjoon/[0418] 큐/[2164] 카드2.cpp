﻿#include <iostream>
#include <queue>
using namespace std;
int N;
queue<int> q;
int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        q.push(i + 1);
    }
    while (q.size() > 1) {
        q.pop();
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
    cout << q.front() << "\n";
    return 0;
}