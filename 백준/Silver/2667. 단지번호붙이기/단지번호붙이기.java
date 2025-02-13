import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Queue;

public class Main {

	static int N;
	static int[][] board;
	static boolean[][] vis;
	static int[] dy = { 1, 0, -1, 0};
	static int[] dx = { 0, 1, 0, -1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		
		board = new int[N][N];
		vis = new boolean[N][N];
		
		for(int i = 0; i < N; i++) {
			String s = br.readLine();
			
			for(int j = 0; j < N; j++) {
				board[i][j] = s.charAt(j) - '0';
			}
		}
		
		Queue<int[]> queue = new ArrayDeque<>();
		List<Integer> answer = new ArrayList<>(); 
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(vis[i][j] || board[i][j] == 0) continue;
				
				vis[i][j] = true;
				queue.offer(new int[] {i, j});
				int size = 0;
				
				while(!queue.isEmpty()) {
					int[] cur = queue.poll();
					
					size++;
					int y = cur[0];
					int x = cur[1];
					
					for(int dir = 0; dir < 4; dir++) {
						int ny = y + dy[dir];
						int nx = x + dx[dir];
						
						if(ny < 0 || ny >= N || nx < 0|| nx >= N) continue;
						if(board[ny][nx] == 0 || vis[ny][nx]) continue;
						
						vis[ny][nx] = true;
						queue.offer(new int[] {ny, nx});
					}
				}
				
				answer.add(size);
			}
		}
		
		Collections.sort(answer);
		
		System.out.println(answer.size());
		
		for(int house : answer) {
			System.out.println(house);
		}
	}
}

