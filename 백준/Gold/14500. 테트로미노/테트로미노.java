import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int[][] board;
	static boolean[][] vis;
	static int N, M, mx;
	
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		board = new int[N][M];
		vis = new boolean[N][M];
		
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		// 모든 좌표에 대해서
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				vis[i][j] = true;
				DFS(new ArrayList<>(List.of(new int[] {i, j})), 1, board[i][j]);
				vis[i][j] = false;
			}
		}
		
		System.out.println(mx);
	}
	
	static void DFS(List<int[]> list, int depth, int sum) {
		if(depth == 4) {
			mx = Math.max(mx, sum);
			
			return;
		}
		
		for(int i = 0; i < list.size(); i++) {
			int x = list.get(i)[0];
			int y = list.get(i)[1];
			for(int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				
				if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
				if(vis[nx][ny]) continue;
				
				list.add(new int[] {nx, ny});
				vis[nx][ny] = true;
				DFS(list, depth + 1, sum + board[nx][ny]);
				vis[nx][ny] = false;
				list.remove(list.size() - 1);
			}
		}
		
		
	}
	
}
