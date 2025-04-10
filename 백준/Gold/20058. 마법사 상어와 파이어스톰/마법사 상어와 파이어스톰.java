import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int[][] board;
	static int N, Q, sum, mx;
	
	// BFS
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	static Queue<int[]> q = new ArrayDeque<>();
	static boolean[][] vis;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		Q = Integer.parseInt(st.nextToken());
		
		board = new int[1 << N][1 << N];
		vis = new boolean[1 << N][1 << N];
		
		for(int i = 0; i < (1 << N); i++) {
			st = new StringTokenizer(br.readLine());
			for(int j = 0; j < (1 << N); j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		

		
		st = new StringTokenizer(br.readLine());
		
		for(int i = 0; i < Q; i++) {
			int L = Integer.parseInt(st.nextToken());
			
			rotate(L);

			decreaseIce();
		}
		
		getSum();
		getMass();
		
		System.out.println(sum);
		System.out.println(mx);
	}
	
	static void rotate(int L) {
	    int size = 1 << L;
	    for (int row = 0; row < (1 << N); row += size) {
	        for (int col = 0; col < (1 << N); col += size) {
	            int[][] temp = new int[size][size];
	            // 회전: 시계 방향 90도
	            for (int i = 0; i < size; i++) {
	                for (int j = 0; j < size; j++) {
	                    temp[j][size - 1 - i] = board[row + i][col + j];
	                }
	            }
	            // 원본에 덮어쓰기
	            for (int i = 0; i < size; i++) {
	                for (int j = 0; j < size; j++) {
	                    board[row + i][col + j] = temp[i][j];
	                }
	            }
	        }
	    }
	}

	
	static void decreaseIce() {
		List<int[]> list = new ArrayList<>();
		
		for(int i = 0; i < (1 << N); i++) {
			for(int j = 0; j < (1 << N); j++) {
				int cntIce = 0;
				
				for(int dir = 0; dir < 4; dir++) {
					
					int nx = i + dx[dir];
					int ny = j + dy[dir];

					if(nx < 0 || nx >= (1 << N) || ny < 0 || ny >= (1 << N)) continue;
					if(board[nx][ny] > 0) cntIce++;
				}
				if(cntIce < 3) {
					list.add(new int[] {i, j});
				}
				
				
			}
		}
		
		for(int[] cur : list) {
			board[cur[0]][cur[1]] = board[cur[0]][cur[1]] == 0 ? board[cur[0]][cur[1]] : board[cur[0]][cur[1]] - 1;
		}
	}
	
	static void getSum() {
		for(int i = 0; i < (1 << N); i++) {
			for(int j = 0; j < (1 << N); j++) {
				sum += board[i][j];
			}
		}
	}
	
	static void getMass() {
		for(int i = 0; i < (1 << N); i++) {
			for(int j = 0; j < (1 << N); j++) {
				if(vis[i][j] || board[i][j] == 0) continue;
				
				int cnt = 0;
				q.offer(new int[] {i, j});
				vis[i][j] = true;
				
				while(!q.isEmpty()) {
					cnt++;
					
					int[] cur = q.poll();
					int x = cur[0];
					int y = cur[1];
					
					for(int dir = 0; dir < 4; dir++) {
						int nx = x + dx[dir];
						int ny = y + dy[dir];
						
						if(nx < 0 || nx >= (1 << N) || ny < 0 || ny >= (1 << N)) continue;
						if(vis[nx][ny] || board[nx][ny] == 0) continue;
						
						q.offer(new int[] {nx, ny});
						vis[nx][ny] = true;
					}
				}
				
				mx = Math.max(mx, cnt);
			}
		}
	}

}
