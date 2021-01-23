#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<int, int>> classi[100];
    int cnt = 0;
    map<string, int> m, genres_number;
    for (int i = 0; i < genres.size(); i++) {
        if (m.find(genres[i]) == m.end())
            m[genres[i]] = plays[i];
        else
            m[genres[i]] += plays[i];
        if (genres_number.find(genres[i]) == genres_number.end()) {
            genres_number[genres[i]] = cnt++;
            classi[genres_number[genres[i]]].push_back(make_pair(plays[i], i));
        }
        else
            classi[genres_number[genres[i]]].push_back(make_pair(plays[i], i));
    }
    vector<pair<int, string>> genres_order;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        genres_order.push_back(make_pair(iter->second, iter->first));
    }
    sort(genres_order.begin(), genres_order.end());
    for (int i = genres_order.size() - 1; i >= 0; i--) {
        string tempgenre = genres_order[i].second;
        sort(classi[genres_number[tempgenre]].begin(), classi[genres_number[tempgenre]].end(), compare);
        for (int j = 0; j < 2; j++) {
            if (classi[genres_number[tempgenre]].size() == 1 && j == 1)
                break;
            answer.push_back(classi[genres_number[tempgenre]][j].second);
        }
    }
    return answer;
}