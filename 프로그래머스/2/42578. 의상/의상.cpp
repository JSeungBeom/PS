#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

unordered_map<string, int> um;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for(int i = 0; i < (int)clothes.size(); i++){
        um[clothes[i][1]]++;
    }
    
    for(auto e : um){
        answer *= (e.Y + 1);
    }
    
    return answer - 1;
}