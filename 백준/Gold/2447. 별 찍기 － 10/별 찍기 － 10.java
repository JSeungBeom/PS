import java.util.Arrays;
import java.util.Scanner;

public class Main {

	static int N;
	static char[][] board = new char[7000][7000];
	
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		
		N = sc.nextInt();
		
		for(int i = 0; i < N; i++) {
			Arrays.fill(board[i], 0, N, ' ');
		}
		
		
		solve(N, 0, 0);
		

		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				sb.append(board[i][j]);
			}
			sb.append("\n");
		}
		
		System.out.println(sb.toString());
	}
	
	static void solve(int N, int r, int c) {
		if(N == 1) {
			board[r][c] = '*';
			return;
		}
		
		int div = N / 3;
		
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				if(i == 1 && j == 1) continue;
				
				solve(div, r + div * i, c + div * j);
			}
		}
		
	}

}
