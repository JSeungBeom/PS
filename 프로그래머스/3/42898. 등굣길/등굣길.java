class Solution {
    static boolean[][] board;
    static int[][] dp;
    static final int MAX = 1000000007;
    
    public int solution(int m, int n, int[][] puddles) {
        int answer = 0;
        
        board = new boolean[n + 1][m + 1];
        dp = new int[n + 1][m + 1];
        
        for(int i = 0; i < puddles.length; i++){
            board[puddles[i][1]][puddles[i][0]] = true;
        }
        
        dp[1][1] = 1;
        
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(!board[i - 1][j])
                    dp[i][j] += (dp[i - 1][j] % MAX);
                if(!board[i][j - 1])
                    dp[i][j] += (dp[i][j - 1] % MAX);
            }
        }
        
        return dp[n][m] % MAX;
    }
}