#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    
    for(int i = 0; i < scoville.size(); i++){
        pq.push(scoville[i]);
    }    
    
    while(pq.top() < K){
        if(pq.size() == 1 || pq.empty()){
            answer = -1;
            break;
        }
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        
        int new_prod = a + (b * 2);
        
        pq.push(new_prod); answer++;
    }
    
    return answer;
}