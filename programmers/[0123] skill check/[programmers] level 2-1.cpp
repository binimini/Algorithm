#include<string>
#include <iostream>
#include <vector>
using namespace std;

bool solution(string s)
{
    vector<char> v;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(')
            v.push_back(s[i]);
        else {
            if (v.empty())
                return false;
            else
                v.pop_back();
        }
    }
    if (!v.empty())
        return false;
    return true;
}