import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main {
	
	static int N;
	static int[][] board;
	static int[][] dp;
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	static int ans;
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	N = Integer.parseInt(br.readLine());
    	
    	board = new int[N][N];
    	dp = new int[N][N];
    	
    	for(int i = 0; i < N; i++) {
    		StringTokenizer st = new StringTokenizer(br.readLine());
    		for(int j = 0; j < N; j++) {
    			board[i][j] = Integer.parseInt(st.nextToken());
    		}
    	}
    	
    	for(int i = 0; i < N; i++) {
    		for(int j = 0; j < N; j++) {
    			ans = Math.max(ans, dfs(i, j));
    		}
    	}
    
    	
    	System.out.println(ans);
    	
	}

	static int dfs(int x, int y) {		
		if(dp[x][y] > 0) return dp[x][y];

		dp[x][y] = 1;
		
		for(int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			
			if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
			if(board[nx][ny] > board[x][y]) {
				dp[x][y] = Math.max(dp[x][y], dfs(nx, ny) + 1); 
			}
		}
		
		return dp[x][y];
	}
	
}
