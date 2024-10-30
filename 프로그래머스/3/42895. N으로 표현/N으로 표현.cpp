#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int getNs(int N, int rep){
    char n = (char) N + '0';
    
    string tmp = "";
    tmp += n;
    
    for(int i = 0; i < rep; i++){
        tmp += n;
    }
    
    return stoi(tmp);
}

int solution(int N, int number) {
    if(N == number) return 1;
    
    vector<int> dp[8];
    
    dp[0].push_back(N);
    
    for(int i = 1; i <= 7; i++){
        dp[i].push_back(getNs(N, i));
        
        for(int j = 0; j < i; j++){
            for(int k = 0; k < i; k++){
                if(j + k + 1 != i) continue;
                
                for(auto a : dp[j]){
                    for(auto b : dp[k]){
                        dp[i].push_back(a + b);
                        if(a - b < 0) continue;
                        dp[i].push_back(a - b);
                        dp[i].push_back(a * b);
                        if(b != 0)
                            dp[i].push_back(a / b);
                    }
                }
            }
        }
        
        if(find(dp[i].begin(), dp[i].end(), number) != dp[i].end())
            return i + 1;
    }
    
    return -1;
}