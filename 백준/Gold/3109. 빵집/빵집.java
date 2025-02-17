import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static char[][] board;
	static boolean[][] vis;
	static int R, C;
	static int ans;
	static int[] dx = {-1, 0, 1};
	static int[] dy = {1, 1, 1};
	static boolean isCompleted;
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        
        board = new char[R][C];
        vis = new boolean[R][C];
        
        for(int i = 0; i < R; i++) {
        	board[i] = br.readLine().toCharArray();
        }
        
        for(int i = 0; i < R; i++) {
        	isCompleted = false;
        	solve(i, 0);
        }
        
        System.out.println(ans);
    }
    
    static void solve(int x, int y) {
    	if(isCompleted) return;
    	
    	if(y == C) {
    		ans++;
    		isCompleted = true;
    		return;
    	}

    	
    	if(x < 0 || x >= R || y < 0 || y >= C) return;
    	if(vis[x][y] || board[x][y] == 'x') return;
    	
    	if(!vis[x][y] && board[x][y] != 'x') {
    		vis[x][y] = true;
    		for(int dir = 0; dir < 3; dir++) {
    			int nx = x + dx[dir];
    			int ny = y + dy[dir];
    			
    			solve(nx, ny);
    		}
    	}
    	
    		
    }

}
