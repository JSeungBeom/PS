import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {

	static int M, N;
	static int[][] board;
	static int[][] dist;
	static int[] dy = { 1, 0, -1, 0};
	static int[] dx = { 0, 1, 0, -1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		M = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
	
		board = new int[N][M];
		dist = new int[N][M];
		
		Queue<int[]> queue = new ArrayDeque<>();
		
		for(int i = 0; i < N; i++) {
			Arrays.fill(dist[i], -1);
		}
		
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				
				if(board[i][j] == 1) {
					queue.offer(new int[] {i, j} );
					dist[i][j] = 0;
				}
			}
		}
		
		while(!queue.isEmpty()) {
			int[] cur = queue.poll();
			
			int y = cur[0];
			int x = cur[1];
			
			for(int dir = 0; dir < 4; dir++) {
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				
				if(ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
				if(dist[ny][nx] >= 0 || board[ny][nx] == -1) continue;
				
				dist[ny][nx] = dist[y][x] + 1;
				queue.offer(new int[] {ny, nx});
			}
		}
		
		int answer = 0;
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < M; j++) {
				if(dist[i][j] == -1 && board[i][j] != -1) {
					System.out.println(-1);
					System.exit(0);
				}
				answer = Math.max(answer, dist[i][j]);
			}
		}
		
		System.out.println(answer);
		
	}
}

