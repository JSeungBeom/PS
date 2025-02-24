import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.StringTokenizer;
public class Main {
	
	static int N, M, D;
	static int[][] board;
	static int[] arr;
	static boolean[] vis;
	static List<Enemy> enemies;
	static List<Enemy> originEnemies = new ArrayList<>();
	static HashSet<Enemy> eliminate = new HashSet<>();
	static int cnt;
	static int ans;
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	
    	N = Integer.parseInt(st.nextToken());
    	M = Integer.parseInt(st.nextToken());
    	D = Integer.parseInt(st.nextToken());
    	
    	board = new int[N][M];
    	arr = new int[3];
    	vis = new boolean[M];
    	
    	for(int i = 0; i < N; i++) {
    		st = new StringTokenizer(br.readLine());
    		for(int j = 0; j < M; j++) {
    			board[i][j] = Integer.parseInt(st.nextToken());
    			if(board[i][j] == 1)
    				originEnemies.add(new Enemy(i, j));
    		}
    	}
    	
    	
    	comb(0, 0);
    	System.out.println(ans);
	}
	
	static void comb(int k, int st) {
		if(k == 3) {
			cnt = 0;
			enemies = new ArrayList<>();
			for(int i = 0; i < originEnemies.size(); i++) {
			    enemies.add(new Enemy(originEnemies.get(i).x, originEnemies.get(i).y));
			}
			while(true) {
				for(int i = 0; i < 3; i++)
					attack(N, arr[i]);
			
				remove();
				move();
				eliminate.clear();
				
				ans = Math.max(ans, cnt);
				
				if(enemies.size() == 0) return;
			}
		}
		
		for(int i = st; i < M; i++) {
			if(vis[i]) continue;
			
			arr[k] = i;
			vis[i] = true;
			comb(k + 1, i);
			vis[i] = false;
		}
	}
	
	static void attack(int x, int y) {
		Collections.sort(enemies, (e1, e2) -> (Math.abs(x - e1.x) + Math.abs(y - e1.y))
				== (Math.abs(x - e2.x) + Math.abs(y - e2.y)) ? e1.y - e2.y : (Math.abs(x - e1.x) + Math.abs(y - e1.y))
						- (Math.abs(x - e2.x) + Math.abs(y - e2.y)));
		
				
		for(int i = 0; i < enemies.size(); i++) {
			int d = (Math.abs(x - enemies.get(i).x) + Math.abs(y - enemies.get(i).y));
			if(d <= D) {
				eliminate.add(enemies.get(i));
				return;
			}
		}		
	}
	
	static void remove() {
		cnt += eliminate.size();
		
		for(Enemy enemy : eliminate) {
			enemies.remove(enemy);
		}
	}
	
	static void move() {
		for(int i = enemies.size() - 1; i >= 0; i--) {
			enemies.get(i).x = enemies.get(i).x + 1;
			if(enemies.get(i).x == N) {
				enemies.remove(i);
			}
		}
		
		
	}
	
	

	static class Enemy{
		int x;
		int y;
		
		Enemy(int x, int y){
			this.x = x;
			this.y = y;
		}

		@Override
		public String toString() {
			return "Enemy [x=" + x + ", y=" + y + "]";
		}
		
		
	}
	
}
