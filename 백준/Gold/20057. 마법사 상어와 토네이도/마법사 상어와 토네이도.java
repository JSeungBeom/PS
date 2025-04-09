import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	
	static int N;
	static int[][] board;
	static int[] dx = { 0, 1, 0, -1 };
	static int[] dy = { -1, 0, 1, 0 };
	static List<Double> list = new ArrayList<>();
	
	static int ans;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		board = new int[N][N];
		list.add(0.07); list.add(0.02);
		for(int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 0; j < N; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		int curX = N / 2;
		int curY = N / 2;
		int dir = -1;
		
		for(int i = 1; i <= N; i++) {
			for(int j = 0; j < 2; j++) {
				dir = (dir + 1) % 4;
			
				for(int k = 0; k < i; k++) {
					curX += dx[dir];
					curY += dy[dir];
					
					if(curX < 0 || curX >= N || curY < 0 || curY >= N) {
						System.out.println(ans);
						return;
					}
					
					dustBlow(curX, curY, dir);
				}
			}
		}
	}
	
	static void dustBlow(int r, int c, int dir) {
		int sideDir1 = (dir == 0 || dir == 2) ? 1 : 0;
		int sideDir2 = (dir == 0 || dir == 2) ? 3 : 2;
		
		int x = r; int y = c;
		int rest = board[r][c];

		// 옆1
		for(int i = 0; i < 2; i++) {
			x += dx[sideDir1];
			y += dy[sideDir1];
			
			if(OOB(x, y)) {
				ans += (int)(board[r][c] * list.get(i));
			}
			else {
	 			board[x][y] += (int)(board[r][c] * list.get(i));	

			}
		
 			rest -= (int)(board[r][c] * list.get(i));
		}
		
		x = r; y = c;
		
		// 옆2
		for(int i = 0; i < 2; i++) {
			x += dx[sideDir2];
			y += dy[sideDir2];
			
			if(OOB(x, y)) {
				ans += (int)(board[r][c] * list.get(i));
			}
			else {
	 			board[x][y] += (board[r][c] * list.get(i));	
			}
			
 			rest -= (int)(board[r][c] * list.get(i));
		}
		
		// 대각선 옆, 앞1
		int nx1 = r + dx[sideDir1] + dx[dir];
		int ny1 = c + dy[sideDir1] + dy[dir];
		
		if(!OOB(nx1, ny1)) {
			board[nx1][ny1] += (board[r][c] * 0.1);
 		} else {
 			ans += (int)(board[r][c] * 0.1);
 		}
		
		rest -= (int)(board[r][c] * 0.1);
		
		// 대각선 옆, 앞2
		int nx2 = r + dx[sideDir2] + dx[dir];
		int ny2 = c + dy[sideDir2] + dy[dir];
		
		if(!OOB(nx2, ny2)) {
			board[nx2][ny2] += (int)(board[r][c] * 0.1);
 		} else {
 			ans += (int)(board[r][c] * 0.1);
 		}
		
		rest -= (int)(board[r][c] * 0.1);
		
		// 대각선 옆, 뒤1
		int nx3 = r + dx[sideDir1] - dx[dir];
		int ny3 = c + dy[sideDir1] - dy[dir];
		
		if(!OOB(nx3, ny3)) {
			board[nx3][ny3] += (int)(board[r][c] * 0.01);
 		} else {
 			ans += (int)(board[r][c] * 0.01);
 		}
		
		rest -= (int)(board[r][c] * 0.01);
		
		// 대각선 옆, 뒤2
		int nx4 = r + dx[sideDir2] - dx[dir];
		int ny4 = c + dy[sideDir2] - dy[dir];
		if(!OOB(nx4, ny4)) {
			board[nx4][ny4] += (int)(board[r][c] * 0.01);
 		} else {
 			ans += (int)(board[r][c] * 0.01);
 		}
		
		rest -= (int)(board[r][c] * 0.01);
		
		// 2칸 앞
		int nx = r + dx[dir] * 2;
		int ny = c + dy[dir] * 2;
		if(!OOB(nx, ny)) {
			board[nx][ny] += (int)(board[r][c] * 0.05);
 		} else {
 			ans += (int)(board[r][c] * 0.05);
 		}
		
		rest -= (int)(board[r][c] * 0.05);
		
		if(!OOB(r + dx[dir], c + dy[dir]))
			board[r + dx[dir]][c + dy[dir]] += rest;
		else
			ans += rest;
		
		board[r][c] = 0;
	}

	static boolean OOB(int x, int y) {
		return x < 0 || x >= N || y < 0 || y >= N;
	}

	

	

}
