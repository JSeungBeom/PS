import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;
public class Main {

	static int K, W, H;
	static int[][] board;
	static int[][][] dist;
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	
	static int[] ddx = {-2, -2, -1, -1, 1, 1, 2, 2};
	static int[] ddy = {-1, 1, -2, 2, -2, 2, -1, 1};
	
	static Queue<int[]> q = new ArrayDeque<>();	
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	K = Integer.parseInt(br.readLine());
    	
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	
    	W = Integer.parseInt(st.nextToken());
    	H = Integer.parseInt(st.nextToken());
    	
    	board = new int[H][W];
    	dist = new int[H][W][K + 1];
    	
    	for(int i = 0; i < H; i++) {
    		st = new StringTokenizer(br.readLine());
    		for(int j = 0; j < W; j++) {
    			Arrays.fill(dist[i][j], -1);
    			board[i][j] = Integer.parseInt(st.nextToken());
    		}
    	}
    	
    	
    	q.offer(new int[] {0, 0, 0});
    	dist[0][0][0] = 0;
    	
    	while(!q.isEmpty()) {
    		int[] cur = q.poll();
    		
    		int x = cur[0];
    		int y = cur[1];
    		int cnt = cur[2];

    		
    		if(cnt < K) {
    			for(int dir = 0; dir < 8; dir++) {
    				int nx = x + ddx[dir];
    				int ny = y + ddy[dir];
    				
    				
    				if(OOB(nx, ny)) continue;
    				if(board[nx][ny] == 1 || dist[nx][ny][cnt + 1] >= 0) continue;
    				
    				dist[nx][ny][cnt + 1] = dist[x][y][cnt] + 1;
    				q.offer(new int[] {nx, ny, cnt + 1});
    			}
    		}
    		
    		for(int dir = 0; dir < 4; dir++) {
    			int nx = x + dx[dir];
    			int ny = y + dy[dir];
    			
    			if(OOB(nx, ny)) continue;
    			if(board[nx][ny] == 1 || dist[nx][ny][cnt] >= 0) continue;
    			
    			dist[nx][ny][cnt] = dist[x][y][cnt] + 1;
    			q.offer(new int[] {nx, ny, cnt});
    		}
    	}
    	
    	int MN = Integer.MAX_VALUE;
    	
    	for(int i = 0; i <= K; i++) {
    		if(dist[H - 1][W - 1][i] != -1)
    			MN = Math.min(dist[H - 1][W - 1][i], MN);
    	}
    	
    	if(MN == Integer.MAX_VALUE)
    		System.out.println(-1);
    	else
    		System.out.println(MN);
     }
	
	static boolean OOB(int x, int y) {
		return x < 0 || x >= H || y < 0 || y >= W;
	}
}
