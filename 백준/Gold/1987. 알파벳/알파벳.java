import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static char[][] board;
	static int R, C;
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	static boolean[] vis = new boolean[26];
	static int len;
	static int MX;
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
    
        board = new char[R][C];
        
        for(int i = 0; i < R; i++) {
        	board[i] = br.readLine().toCharArray();
        }
        
        vis[board[0][0] - 'A'] = true;
        dfs(0, 0, 1);
        
        System.out.println(MX);
    }
    
    static void dfs(int x, int y, int len) {
    	for(int dir = 0; dir < 4; dir++) {
    		int nx = x + dx[dir];
    		int ny = y + dy[dir];

    		if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;

    		if(vis[board[nx][ny] - 'A']) continue;
  
    		vis[board[nx][ny] - 'A'] = true;
    		dfs(nx, ny, len + 1);
    		vis[board[nx][ny] - 'A'] = false;
    	}
    	
    	MX = Math.max(MX, len);
    }
    
    
    

}
