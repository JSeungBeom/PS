#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    
    for(int i = 0; i < progresses.size(); i++){
        int rest = 100 - progresses[i];
        int days;
        
        if(rest % speeds[i] == 0)
            days = rest / speeds[i];
        else
            days = rest / speeds[i] + 1;
        
        q.push(days);
    }
    
    int cnt = 1;
    int pre = 0;
    
    while(!q.empty()){
        pre = max(pre, q.front()); q.pop();
        if(q.empty()){
            answer.push_back(cnt);
            break;
        }
        int cur = q.front();
                
        if(cur <= pre)
            cnt++;
        else{
            answer.push_back(cnt);
            cnt = 1;
        }
    }
     
    return answer;
}