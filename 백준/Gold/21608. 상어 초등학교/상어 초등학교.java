import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int N;
	static Student[][] board;
	
	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, 1, 0, -1};
	
	static int[][] friends;
	static Queue<Integer> q = new ArrayDeque<>();
	static boolean[][] vis;
	
	static int ans;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		
		board = new Student[N][N];
		friends = new int[(N * N) + 1][4];
		vis = new boolean[N][N];
		
		for(int i = 0; i < N * N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int num = Integer.parseInt(st.nextToken());
			
			q.offer(num);
			
			for(int j = 0; j < 4; j++) {
				friends[num][j] = Integer.parseInt(st.nextToken());
			}
		}
		
		
		for(int rep = 0; rep < N * N; rep++) {
			
			int num = q.poll();
			
			PriorityQueue<Student> pq = new PriorityQueue<>((s1, s2) -> s1.fav == s2.fav ? (s1.empty == s2.empty ? (s1.r == s2.r ? s1.c - s2.c : s1.r - s2.r) : s2.empty - s1.empty ) : s2.fav - s1.fav);

			for(int i = 0; i < N; i++) {
				for(int j = 0; j < N; j++) {
					if(vis[i][j]) continue;
					
					int fav = 0;
					int empty = 0;
					
					for(int dir = 0; dir < 4; dir++) {
						int nx = i + dx[dir];
						int ny = j + dy[dir];
							
						if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
						if(board[nx][ny] == null) {
							empty++; continue;
						}
						
						for(int k = 0; k < 4; k++) {
							if(board[nx][ny].num == friends[num][k]) fav++;
						}	
					}
					
					pq.add(new Student(fav, empty, i, j, num));
					
				}
			}
			
			Student student = pq.poll();
			
			board[student.r][student.c] = student;
			vis[student.r][student.c] = true;
			

		}
		

	
		
		for(int i = 0; i < N; i++) {
			for(int j = 0; j < N; j++) {
				int fav = 0;
				
				for(int dir = 0; dir < 4; dir++) {
					int nx = i + dx[dir];
					int ny = j + dy[dir];
					
					if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
					
					for(int k = 0; k < 4; k++) {
						if(friends[board[i][j].num][k] == board[nx][ny].num)
							fav++;
					}
				}
				switch(fav) {
					case 0:
						break;
					case 1:
						ans += 1; break;
					case 2:
						ans += 10; break;
					case 3:
						ans += 100; break;
					case 4:
						ans += 1000; break;
				}
			}
		}
		
		System.out.println(ans);
	}
	
	static class Student {
		int fav;
		int empty;
		int r;
		int c;
		int num;
		
		Student(int fav, int empty, int r, int c, int num){
			this.fav = fav; 
			this.empty = empty;
			this.r = r;
			this.c = c;
			this.num = num;
		}

		@Override
		public String toString() {
			return "Student [fav=" + fav + ", empty=" + empty + ", r=" + r + ", c=" + c + ", num=" + num + "]";
		}
		
		
	}
	

}
