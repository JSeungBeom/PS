#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> s;

    char last = words[0][words[0].length() - 1];
    s.insert(words[0]);
    int num = 1;
    int order = 1;

    for (int i = 1; i < words.size(); i++) {
        char first = words[i].front();
        order++;
        if (order > n) {
            num++;
            order = 1;
        }
        if (first != last || s.find(words[i]) != s.end()) {
            answer.push_back(order);
            answer.push_back(num);
            break;
        }

        s.insert(words[i]);
        last = words[i].back();
    }

    if (answer.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}