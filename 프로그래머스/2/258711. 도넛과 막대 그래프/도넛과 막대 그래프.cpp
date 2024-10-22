#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int out_deg[1000005];
int in_deg[1000005];
vector<int> adj[1000005];

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    
    int mx = 0;
    
    for(int i = 0; i < edges.size(); i++){
        out_deg[edges[i][0]]++;
        in_deg[edges[i][1]]++;
        adj[edges[i][0]].push_back(edges[i][1]);

        mx = max(mx, edges[i][0]);
        mx = max(mx, edges[i][1]);
    }
    
    int rm = 0;
    
    for(int i = 1; i <= mx; i++){
        if(out_deg[i] >= 2 && in_deg[i] == 0){
            answer.push_back(i); rm = i;
        }
    }
    
    for(int i = 0; i < edges.size(); i++){
        if(edges[i][0] == rm)
            in_deg[edges[i][1]]--;
    }
    
    int donut = 0, stick = 0, eight = 0;
    
    for(int st : adj[rm]){        
        queue<int> q;
                
        q.push(st);
        
        while(1){
            int cur = q.front(); q.pop();
            
            bool is_over = 0;
            
            if(adj[cur].empty()) {
                stick++; break;
            }
            
            for(int nxt : adj[cur]){
                q.push(nxt);
            
                if(in_deg[nxt] == 2 && out_deg[nxt] == 2){
                    eight++; is_over = 1;
                    break;
                }
                
                if(nxt == st){
                    donut++; is_over = 1;
                    break;
                }
            }
            
            if(is_over) break;
        }
    }
    
    answer.push_back(donut);
    answer.push_back(stick);
    answer.push_back(eight);
    
    return answer;
}