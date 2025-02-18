import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main {
	
    static int N, M, ans;
    static int[][] board;
    static boolean[][] vis;
    static int r, c, d;
    
    static int[] dx = { -1, 0, 1, 0 };
    static int[] dy = { 0, 1, 0, -1 };
    
    public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	
    	N = Integer.parseInt(st.nextToken());
    	M = Integer.parseInt(st.nextToken());
    	
    	board = new int[N][M];
    	vis = new boolean[N][M];
    	
    	st = new StringTokenizer(br.readLine());
    	
    	r = Integer.parseInt(st.nextToken());
    	c = Integer.parseInt(st.nextToken());
    	d = Integer.parseInt(st.nextToken());
    	
    	for(int i = 0; i < N; i++) {
    		st = new StringTokenizer(br.readLine());
    		for(int j = 0; j < M; j++) {
    			board[i][j] = Integer.parseInt(st.nextToken());
    		}
    	}
    	
    	clean(r, c, d);    
    }
    
    static void clean(int x, int y, int d) {
    	if(!vis[x][y]) {
    		vis[x][y] = true;
    		ans++;
    	}
    	
    	int cnt = 0;
    	
    	for(int dir = 0; dir < 4; dir++) {
    		int nx = x + dx[dir];
    		int ny = y + dy[dir];
    		
    		if(nx < 0 || nx >= N || ny < 0 || ny >= M) cnt++;
    		if(vis[nx][ny] || board[nx][ny] == 1) cnt++;
    	}
    	
    	if(cnt == 4) {
    		int nx = x + dx[(d + 2) % 4];
    		int ny = y + dy[(d + 2) % 4];
    		
    		if(board[nx][ny] == 1) {
    			System.out.println(ans); System.exit(0);
    		}
    		else {
    			clean(nx, ny, d);
    		}
    	}
    	
    	for(int dir = 0; dir < 4; dir++) {
    		d += 3;
    		int nx = x + dx[d % 4];
    		int ny = y + dy[d % 4];
    		
    		if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
    		if(vis[nx][ny] || board[nx][ny] == 1) continue;
    		
    		clean(nx, ny, d % 4);
    	}
    }
}
