#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solve(int mid, vector<int> diffs, vector<int> times, long long limit) {
    long long sum = 0;
    int time_prev = 0;
    for(int i = 0; i < diffs.size(); i++){
        if(diffs[i] <= mid){
            sum += times[i];
        }
        else{
            sum += ((times[i] + time_prev) * (diffs[i] - mid));
            sum += times[i];
        }
        time_prev = times[i];
    }
    
    if(sum > limit) return 0;
    
    return 1;
    
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    
    int st = 1;
    int en = 200000;
    
    int answer = 0x7fffffff;
    
    while(st <= en){
        int mid = (st + en) / 2;
        
        if(solve(mid, diffs, times, limit)){ 
            en = mid - 1;
            answer = min(answer, mid);
        }
        else st = mid + 1;
    }
    
    return answer;
}