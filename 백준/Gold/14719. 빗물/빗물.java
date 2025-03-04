import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int H, W;
	static boolean[][] board;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		H = Integer.parseInt(st.nextToken());
		W = Integer.parseInt(st.nextToken());
		
		board = new boolean[H][W];
		
		st = new StringTokenizer(br.readLine());
		
		for(int i = 0; i < W; i++) {
			int h = Integer.parseInt(st.nextToken());
			fillBlock(i, h);
		}
		

		System.out.println(countRain());
	}
	
	static void fillBlock(int w, int h) {
		for(int j = H - 1; j >= H - h; j--) {
			board[j][w] = true;
		}
	}
	
	static int countRain() {
		int cnt = 0;
		
		for(int i = 0; i < H; i++) {
			int block = -1;
			
			for(int j = 0; j < W; j++) {
				if(board[i][j] == true) {
					if(block >= 0) {
						cnt += (j - block - 1);
					}
					block = j;
				}
			}
		}
		
		return cnt;
	}
	
}
