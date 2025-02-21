import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main {
	
	static int N;
	static int[][] board;
	static boolean[][] vis;
	static int[] dx = { 0, 1, 1 };
	static int[] dy = { 1, 0, 1 };
	static int ans;
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	N = Integer.parseInt(br.readLine());
    	
    	board = new int[N + 1][N + 1];
    	vis = new boolean[N + 1][N + 1];
    	
    	for(int i = 1; i <= N; i++) {
    		StringTokenizer st = new StringTokenizer(br.readLine());
    		for(int j = 1; j <= N; j++) {
    			board[i][j]	= Integer.parseInt(st.nextToken());
    		}
    	}
    	
    	dfs(1, 2, 0);
    	System.out.println(ans);
	}	
	
	static void dfs(int x, int y, int dir) {
		if(x == N && y == N) {
			ans++;
			return;
		}
		
		vis[x][y] = true;
		
		
		for(int d = 0; d < 3; d++) {
			if(dir == 0 && d == 1) continue;
			if(dir == 1 && d == 0) continue;
			
			int nx = x + dx[d];
			int ny = y + dy[d];
			
			if(nx < 0 || nx > N || ny < 0 || ny > N) continue;
			
			if(d < 2) {
				if(board[nx][ny] == 0 && !vis[nx][ny]) {
					dfs(nx, ny, d);
					vis[nx][ny] = false;
				}
			}
			else {
				if(board[nx][ny] == 0 && board[nx - 1][ny] == 0 &&
						board[nx][ny - 1] == 0 && !vis[nx][ny]) {
					dfs(nx, ny, d);
					vis[nx][ny] = false;
				}
			}
		}
	}
	
}
