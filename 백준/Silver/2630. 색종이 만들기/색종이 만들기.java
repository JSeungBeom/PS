import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int[][] board;
	static int total;
	static int blue;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		N = Integer.parseInt(br.readLine());
		board = new int[N][N];
		
		for(int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			for(int j = 0; j < N; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		solve(N, 0, 0);
		
		System.out.println(total - blue);
		System.out.println(blue);
		
	}
	
	
	static void solve(int N, int x, int y) {
		if(N == 0)
			return;
		
		if(chk(N, x, y)) {
			blue += board[x][y];
			total++;
			return;
		}
		
		// Divide
		solve(N / 2, x, y);
		solve(N / 2, x + N / 2, y);
		solve(N / 2, x, y + N / 2);
		solve(N / 2, x + N / 2, y + N / 2);
	}
	
	static boolean chk(int N, int x, int y) {
		for(int i = x; i < x + N; i++) {
			for(int j = y; j < y + N; j++) {
				if(board[x][y] != board[i][j])
					return false;
			}
		}
		
		return true;
	}
	
}

