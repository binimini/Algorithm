#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int upper_bound(int start, int end, vector<int>& people, int key) {
    int s = start, e = end, m;
    while (e - s > 0) {
        m = (s + e) / 2;
        if (people[m] <= key)
            s = m + 1;
        else
            e = m;
    }
    return e;
}
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int match = 0, idx = people.size();
    for (int i = 0; i < people.size(); i++) {//NlogN
        if (i + 1 >= idx) break;
        idx = upper_bound(i + 1, idx, people, limit - people[i]);

        if (idx - 1 < i + 1)
            break;
        else {
            match++;
            idx = idx - 1;
        }
    }
    answer = people.size() - match * 2 + match;
    return answer;
}