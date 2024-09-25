#include <string>
#include <vector>
using ll = long long;

using namespace std;

ll dp[5005];
int mod = 1e9 + 7;

int solution(int n) {
    
    if(n % 2 == 1)
        return 0;
    
    dp[2] = 3;
    dp[0] = 1;
    
    for(int i = 4; i <= 5000; i += 2) {
        dp[i] = dp[i - 2] * 3 % mod;
        
        for(int j = i - 4; j >= 0; j -= 2){
            dp[i] += dp[j] * 2;
        } 
        
        dp[i] %= mod;
        
    } 
    
    int answer = dp[n];
    return answer;
}