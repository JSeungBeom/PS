import java.io.BufferedReader;
import java.io.InputStreamReader;
public class Main {
	
	static int N;
	static int[] stairs;
	static int[][] dp;
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	N = Integer.parseInt(br.readLine());
    	stairs = new int[N + 1];
    	dp = new int[N + 1][4];
    	
    	for(int i = 1; i <= N; i++) {
    		stairs[i] = Integer.parseInt(br.readLine());
    	}
    	
    	dp[1][1] = stairs[1]; // 기저 조건
    	
    	for(int i = 2; i <= N; i++) {
			dp[i][1] = Math.max(dp[i - 2][1], dp[i - 2][2]) + stairs[i];
    		dp[i][2] = dp[i - 1][1] + stairs[i];
    			
    	}
    	
    	System.out.println(Math.max(dp[N][1], dp[N][2]));
	}	

	
}
