#include <bits/stdc++.h>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
        
    for(int x = 1; x <= r2; x++){
        int minY = ceil(sqrt((long long)r1 * r1 - (long long)x * x));
        int maxY = floor(sqrt((long long)r2 * r2 - (long long)x * x));
        
        if(r1 < x)
            minY = 0;
        
        answer += (maxY - minY + 1);
    }
    
    answer *= 4;
    
    return answer;
}