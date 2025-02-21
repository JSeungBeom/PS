import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main {
	
	static int N;
	static int[][] board;
	static int[][][] dp;
	
	static int ans;
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	N = Integer.parseInt(br.readLine());
    	
    	board = new int[N + 1][N + 1];
    	dp = new int[N + 1][N + 1][3];
    	
    	for(int i = 1; i <= N; i++) {
    		StringTokenizer st = new StringTokenizer(br.readLine());
    		for(int j = 1; j <= N; j++) {
    			board[i][j]	= Integer.parseInt(st.nextToken());
    		}
    	}
    	
    	dp[1][2][0] = 1;
    	for(int i = 1; i <= N; i++) {
    		for(int j = 1; j <= N; j++) {
    			if(board[i][j] != 1) {

    				dp[i][j][0] += dp[i][j - 1][0] + dp[i][j - 1][2];
    				dp[i][j][1] += dp[i - 1][j][1] + dp[i - 1][j][2];
    			}
    			if(board[i][j] != 1 && board[i - 1][j] != 1 && board[i][j - 1] != 1) {
    				dp[i][j][2] += dp[i - 1][j - 1][0] + dp[i - 1][j - 1][1] + dp[i - 1][j - 1][2];
    			}
    		}
    	}
    	

    	System.out.println(dp[N][N][0] + dp[N][N][1] + dp[N][N][2]);
	}	

	
}
