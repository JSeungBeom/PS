import java.util.*;

class Solution {
    
    static int[][] dp;
    
    public int solution(int[][] info, int n, int m) {
        int answer = 0;
        int size = info.length;
        
        dp = new int[size + 1][m];
        
        for(int i = 1; i <= size; i++){
            Arrays.fill(dp[i], Integer.MAX_VALUE);
        }
        
        for(int i = 1; i <= size; i++){
            for(int j = 0; j < m; j++){
                dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + info[i - 1][0]);
                
                if(j + info[i - 1][1] < m)
                    dp[i][j + info[i - 1][1]] = Math.min(dp[i - 1][j], dp[i][j + info[i - 1][1]]);
            }
        }
        
        int MN = Integer.MAX_VALUE;
        
        for(int i = 0; i < m; i++){
            MN = Math.min(MN, dp[size][i]);
        }
        
        if(MN >= n)
            MN = -1;
        
        return MN;
    }
}