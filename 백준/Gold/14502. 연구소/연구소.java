import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;
public class Main {

	static int N, M;
	static int[][] board;
	static int[][] cpy;
	static List<int[]> blank = new ArrayList<>();
	static List<int[]> virus = new ArrayList<>();
	static Wall[] walls = new Wall[3];
	static Queue<int[]> q = new ArrayDeque<>();
	static boolean[][] vis;
	static int[] dx = {1, 0, -1, 0};
	static int[] dy	= {0, 1, 0, -1};
	static int ans;
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    		
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	
    	N = Integer.parseInt(st.nextToken());
    	M = Integer.parseInt(st.nextToken());
    	
    	board = new int[N][M];
    	cpy = new int[N][M];
    	vis = new boolean[N][M];
    	
    	for(int i = 0; i < N; i++) {
    		st = new StringTokenizer(br.readLine());
    		
    		for(int j = 0; j < M; j++) {
    			board[i][j] = Integer.parseInt(st.nextToken());
    			if(board[i][j] == 0)
    				blank.add(new int[] {i, j});
    			if(board[i][j] == 2)
    				virus.add(new int[] {i, j});
    		}
    	}
    	
    	for(int i = 0; i < N; i++) {
    		for(int j = 0; j < M; j++)
    			cpy[i][j] = board[i][j];
    	}
    
    	comb(0, 0);
    	
    	System.out.println(ans);
    }
	

	static class Wall {
		int x;
		int y;
		
		Wall(int x, int y){
			this.x = x;
			this.y = y;
		}
	}
	
	static void comb(int srcIdx, int tgtIdx) {
		if(tgtIdx == 3) {
			for(int i = 0; i < 3; i++) {
				cpy[walls[i].x][walls[i].y] = 1;
			}
			
			bfs();
			ans = Math.max(ans, check());
			
			for(int i = 0; i < N; i++) {
	    		for(int j = 0; j < M; j++)
	    			cpy[i][j] = board[i][j];
	    	}
			return;
		}
		
		if(srcIdx == blank.size()) return;
		
		walls[tgtIdx] = new Wall(blank.get(srcIdx)[0], blank.get(srcIdx)[1]);
		comb(srcIdx + 1, tgtIdx + 1);
		comb(srcIdx + 1, tgtIdx);
	}
	
	static void bfs() {
		for(int i = 0; i < N; i++)
			Arrays.fill(vis[i], false);
		
		for(int[] cur : virus) {
			q.offer(cur);
			vis[cur[0]][cur[1]] = true;
		}
		
		while(!q.isEmpty()) {
			int[] cur = q.poll();
			int x = cur[0];
			int y = cur[1];
			
			for(int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				
				if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if(cpy[nx][ny] != 0 || vis[nx][ny]) continue;
				
				vis[nx][ny] = true;
				cpy[nx][ny] = 2;
				q.offer(new int[] {nx, ny});
			}
		}
	}
	
	static int check() {
		int cnt = 0;
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(cpy[i][j] == 0)
					cnt++;
			}
		}
		
		return cnt;
	}
	
}
