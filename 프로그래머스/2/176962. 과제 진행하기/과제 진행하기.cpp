#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <tuple>

#define X first
#define Y second

using namespace std;

int tominute(string time){
    int minute = 0;
    string tmp = "";
    
    // 시간 추출
    for(int i = 0; i < 2; i++){
        tmp += time[i];            
    }  
    
    minute += stoi(tmp) * 60; // 시간 -> 분 
    
    tmp = "";
    
    // 분 추출
    for(int i = 3; i < 5; i++){
        tmp += time[i];
    }
    
    minute += stoi(tmp); // 분
    
    return minute;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    
    vector<tuple<int, int, string>> v;
    
    stack<pair<string, int>> st;
    
    int n = (int)plans.size();
    
    // int형 변환 후 저장
    // start, playtime, name 순
    for(int i = 0; i < n; i++){
        v.push_back({tominute(plans[i][1]), stoi(plans[i][2]), plans[i][0]});
    }
    
    // start순으로 정렬
    sort(v.begin(), v.end());
    
    int a, b;
    string c;
    tie(a, b, c) = v[0];
    int cur_time = a;
    
    for(int i = 0; i < (int)v.size(); i++){
        int start, playtime, nxt_st, nxt_pt; 
        string name, nxt_name;
                
        tie(start, playtime, name) = v[i];
        
        // 마지막 남은 작업들 처리
        if(i == (int)v.size() - 1){
            answer.push_back(name);
            
            while(!st.empty()){
                auto cur = st.top(); st.pop();
                
                answer.push_back(cur.X);
            }
            
            break;
        }
        
        tie(nxt_st, nxt_pt, nxt_name) = v[i + 1];
        
        if(cur_time + playtime > nxt_st){
            int resttime = playtime - (nxt_st - start);
            cur_time = nxt_st;
            st.push({name, resttime});
        }
        else{
            answer.push_back(name);
            cur_time += playtime;
            
            // 쌓여있는 작업들 처리
            while(!st.empty()) {
                auto cur = st.top(); st.pop();
                
                // 작업 시간이 다음 시작 시간 보다 긴 경우
                if(cur_time + cur.Y > nxt_st){
                    int resttime = cur.Y - (nxt_st - cur_time); // 잔여 시간
                    cur_time = nxt_st; // 현재 시간 갱신
                    st.push({cur.X, resttime});
                    break;
                }
                else{ // 작업 시간이 다음 시작 시간보다 짧은 경우
                    cur_time += cur.Y; // 현재 시간 갱신
                    answer.push_back(cur.X); // 처리 
                }
            }
            
            // 스택이 비었다면 다음 작업으로
            if(st.empty()) {
                cur_time = nxt_st;
                continue;
            }
        }
    }
    
    
    return answer;
}