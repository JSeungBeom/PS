import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
public class Main {

	static int n, m;
	static int[][] board;
	static int[][] dp;
	
    public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	
    	n = Integer.parseInt(st.nextToken());
    	m = Integer.parseInt(st.nextToken());
    	
    	board = new int[n + 1][m + 1];
    	dp = new int[n + 1][m + 1];

    	for(int i = 1; i <= n; i++) {
    		char[] c = br.readLine().toCharArray();
    		
    		for(int j = 1; j <= m; j++) {
    			board[i][j] = c[j - 1] - '0';
    		}
    	}
    		
    	int MX = 0;
    	
    	for(int i = 1; i <= n; i++) {
    		for(int j = 1; j <= m; j++) {
    			if(board[i][j] == 1) {
    				dp[i][j] = Math.min(Math.min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
    				MX = Math.max(dp[i][j] * dp[i][j], MX);
    			}
    		}
    	}
    	
    	System.out.println(MX);
    }
}
