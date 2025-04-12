import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M, ans;
	static int[][] board;
	static boolean[][] vis;
	static PriorityQueue<Group> pq = new PriorityQueue<>((o1, o2) -> o1.count == o2.count ? (o1.rainbow == o2.rainbow ? (o1.r == o2.r ? o2.c - o1.c : o2.r - o1.r) : o2.rainbow - o1.rainbow) : o2.count - o1.count);
	static Queue<int[]> q = new ArrayDeque<>();
	
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		board = new int[N][N];
		vis = new boolean[N][N];
		
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			
			for(int j = 0; j < N; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		while(true) {
			pq.clear();
			findGroup();
			
			if(pq.isEmpty()) break;
			
			eraseGroup();

			moveAll();
	
			rotate();

			moveAll();
		}
			
		
		
		System.out.println(ans);
	}
	
	static void rotate() {
		int[][] tmp = new int[N][N];
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				tmp[N - 1 - j][i] = board[i][j];
			}
		}
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				board[i][j] = tmp[i][j];
			}
		}
	}
	
	static void moveAll() {
		for(int i = N - 1; i >= 0; i--) {
			for(int j = 0; j < N; j++) {
				if(board[i][j] >= 0) {
					for(int k = i; k < N - 1; k++) {
						if(board[k + 1][j] == -2) {
							board[k + 1][j] = board[k][j];
							board[k][j] = -2;
						}
						else break;
						
					}
				}
			}
		}
	}
	
	static void eraseGroup() {
		for(int i = 0; i < N; i++) {
			Arrays.fill(vis[i], false);
		}
		
		Group group = pq.peek();
		
		q.offer(new int[] {group.r, group.c});
		vis[group.r][group.c] = true;
		ans += (group.count * group.count);
		
		while(!q.isEmpty()) {
			int[] cur = q.poll();
			
			int x = cur[0];
			int y = cur[1];
			
			for(int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				
				if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
				if(vis[nx][ny] || (board[nx][ny] != group.color && board[nx][ny] != 0)) continue;
				
				q.offer(new int[] {nx, ny});
				vis[nx][ny] = true;
			}
			
			board[x][y] = -2;
		}
		
		
	}
	
	static void findGroup() {
		for(int i = 0; i < N; i++) {
			Arrays.fill(vis[i], false);
		}
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				if(vis[i][j] || board[i][j] <= 0) continue;
				
				List<int[]> zeros = new ArrayList<>();
				vis[i][j] = true;
				q.offer(new int[] {i, j});
				int cnt = 0;
				int rainbow = 0;
				
				while(!q.isEmpty()) {
					int[] cur = q.poll();
					
					int x = cur[0];
					int y = cur[1];
					if(board[x][y] == 0) {
						zeros.add(new int[] {x, y});
						rainbow++;
					}
					cnt++;
					
					for(int dir = 0; dir < 4; dir++) {
						int nx = x + dx[dir];
						int ny = y + dy[dir];
						
						if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if(vis[nx][ny] || (board[nx][ny] != board[i][j] && board[nx][ny] != 0)) continue;
						
						q.offer(new int[] {nx, ny});
						vis[nx][ny] = true;
					}
				}
				
				for(int[] zero : zeros) {
					vis[zero[0]][zero[1]] = false;
				}
				
				if(cnt < 2) continue;
				
				pq.offer(new Group(i, j, cnt, board[i][j], rainbow));
			}
		}
	}
	
	static class Group {
		int r;
		int c;
		int count;
		int color;
		int rainbow;
		
		Group(int r, int c, int count, int color, int rainbow){
			this.r = r;
			this.c = c;
			this.count = count;
			this.color = color;
			this.rainbow = rainbow;
		}

		@Override
		public String toString() {
			return "Group [r=" + r + ", c=" + c + ", count=" + count + ", color=" + color + "]";
		}

		
	}
}
