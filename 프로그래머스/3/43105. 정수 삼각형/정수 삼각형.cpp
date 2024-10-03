#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int dp[505][505];

int solution(vector<vector<int>> triangle) {
    
    int n = triangle.size();
    
    dp[0][0] = triangle[0][0];
    
    for(int i = 1; i < n; i++){
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
        }
    }
    
    int answer = *max_element(dp[n - 1], dp[n - 1] + n + 1);
    
    return answer;
}