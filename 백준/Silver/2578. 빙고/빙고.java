import java.io.*;
import java.util.*;

public class Main {

	static int[][] board = new int[5][5];
	static boolean bingo;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		for(int i = 0; i < 5; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 0; j < 5; j++){
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		for(int i = 0; i < 5; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 0; j < 5; j++){
				int x = Integer.parseInt(st.nextToken());
				if(!bingo) {
					eraseNum(x);
					chk();
					if(bingo)
						System.out.println(i * 5 + (j + 1));
				}
			}
		}			
	}

	static void eraseNum(int num) {
		for(int i = 0; i < 5; i++) {
			for(int j = 0; j < 5; j++) {
				if(board[i][j] == num) {
					board[i][j] = 0;
					return;
				}
			}
		}

	}

	static void chk() {
		int cnt = 0;
		// 세로
		for(int i = 0; i < 5; i++){
			boolean flag = true;
			for(int j = 0; j < 5; j++){
				if(board[i][j] != 0) {
					flag = false;
					break;
				}
			}
			if(flag) cnt++;
		}

		// 가로
		for(int i = 0; i < 5; i++){
			boolean flag = true;
			for(int j = 0; j < 5; j++){
				if(board[j][i] != 0) {
					flag = false;
					break;
				}
			}
			if(flag) cnt++;
		}

		// 대각선 오른쪽 아래
		boolean flag = true;
		for(int i = 0; i < 5; i++){
			if(board[i][i] != 0) {
				flag = false;
				break;
			}
		}

		if(flag) cnt++;
		
		// 대각선 오른쪽 위
		flag = true;
		for(int i = 0; i < 5; i++){
			if(board[i][4 - i] != 0) {
				flag = false;
				break;
			}
		}
		if(flag) cnt++;

		if(cnt >= 3) bingo = true;
	}
	
}
