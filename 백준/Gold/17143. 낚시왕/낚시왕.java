import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int R, C, M;
	static List<Shark> sharks = new ArrayList<>();
	static Shark[][] board;
	static int answer;
	static int[] dx = {0, -1, 1, 0, 0};
	static int[] dy = {0, 0, 0, 1, -1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		R = Integer.parseInt(st.nextToken());
		C = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		board = new Shark[R + 1][C + 1];
		
		for(int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			
			int r = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			int s = Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			int z = Integer.parseInt(st.nextToken());
			
			Shark shark = new Shark(r, c, s, d, z);
			
			sharks.add(shark);
		}
		
		adjustSharkSpeed();
		
		for(int i = 1; i <= C; i++) {
			init_board();

			getShark(i);

			moveShark();

			eraseDupShark();

		}
		
		System.out.println(answer);
	}
	
	static void init_board() {
		for(int i = 1; i <= R; i++) {
			Arrays.fill(board[i], null);
		}
		
		for(Shark shark : sharks) {
			board[shark.r][shark.c] = shark;
		}
	}
	
	// 상어 잡기
	static void getShark(int c) {
		for(int i = 1; i <= R; i++) {
			if(board[i][c] != null) {
				answer += board[i][c].z; // + 사이즈
				eraseShark(i, c); // 잡은 상어 지우기
				return;
			}
		}
		
		return;
	}
	
	// 상어 지우기
	static void eraseShark(int r, int c) {
		for(int i = sharks.size() - 1; i >= 0; i--) {
			if(sharks.get(i).r == r && sharks.get(i).c == c) {
				sharks.remove(i);
				return;
			}
		}
	}
	
	// 속력 조정
	static void adjustSharkSpeed() {
		for(Shark shark : sharks) {
			if(shark.d <= 2) {
				shark.s %= ((R * 2) - 2);
			} 
			else {
				shark.s %= ((C * 2) - 2);
			}
		}
	}
	
	// 상어 이동
	static void moveShark() {
		for(Shark shark : sharks) {
			for(int i = 0; i < shark.s; i++) {
				int nx = shark.r + dx[shark.d];
				int ny = shark.c + dy[shark.d];
				
				if(nx < 1 || nx > R || ny < 1 || ny > C) {
					switch(shark.d) {
						case 1 : shark.d = 2; break;
						case 2 : shark.d = 1; break;
						case 3 : shark.d = 4; break;
						case 4 : shark.d = 3; break;
					}
					
					nx = shark.r + dx[shark.d];
					ny = shark.c + dy[shark.d];
				}
				
				shark.r = nx;
				shark.c = ny;
			}
		}
	}
	
	// 상어 중복 제거
	static void eraseDupShark() {
		Collections.sort(sharks, (s1, s2) -> (s1.r == s2.r ? (s1.c == s2.c ? s1.z - s2.z : s1.c - s2.c) : s1.r - s2.r));
		
		int r = 0, c = 0, max = 0;
		
		for(int i = sharks.size() - 1; i >= 0; i--) {
			if(r == sharks.get(i).r && c == sharks.get(i).c) {
				sharks.remove(i);
			}
			else {
				r = sharks.get(i).r;
				c = sharks.get(i).c;
			}
		}
	}
	
	
	
	static class Shark {
		int r; int c; int s; int d; int z;

		public Shark(int r, int c, int s, int d, int z) {
			this.r = r;
			this.c = c;
			this.s = s;
			this.d = d;
			this.z = z;
		}

		@Override
		public String toString() {
			return "Shark [r=" + r + ", c=" + c + ", s=" + s + ", d=" + d + ", z=" + z + "]";
		}

			
		
	}
}
