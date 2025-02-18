import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int N;
	static int[][] board;
	static int[][] dist;
	static int[] dx = {-1, 0, 1, 0};
	static int[] dy = {0, -1, 0, 1};
	static int size = 2;
	static int eaten = 0;
	static int distance, start_x, start_y;
	static boolean isCompleted;
	static Queue<int[]> q = new ArrayDeque<>();
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
        N = Integer.parseInt(br.readLine());
        
        board = new int[N][N];
        dist = new int[N][N];
        
        // 초기화
    	for(int i = 0; i < N; i++) {
    		Arrays.fill(dist[i], -1);
    	}
    	
        for(int i = 0; i < N; i++) {
        	StringTokenizer st = new StringTokenizer(br.readLine());
        	
        	for(int j = 0; j < N; j++) {
        		board[i][j] = Integer.parseInt(st.nextToken());
        		
        		if(board[i][j] == 9) {
        			board[i][j] = 0;
        			start_x = i;
        			start_y = j;
        		}
        	}
        }
        
        while(!isCompleted) {
        	q.offer(new int[] {start_x, start_y});
        	dist[start_x][start_y] = 0;
        	BFS(); // 거리 계산
        	eat(); // 먹기
        	
        	
        	// 초기화
        	for(int i = 0; i < N; i++) {
        		Arrays.fill(dist[i], -1);
        	}
        	
        	
        	
        }
        
        System.out.println(distance);
        
        
    }
    
    static void BFS() {
    	while(!q.isEmpty()) {
    		int[] cur = q.poll();
    		int x = cur[0];
    		int y = cur[1];
    		
    		for(int dir = 0; dir < 4; dir++) {
    			int nx = x + dx[dir];
    			int ny = y + dy[dir];
    			
    			if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
    			if(board[nx][ny] > size || dist[nx][ny]	>= 0) continue;
    			
    			dist[nx][ny] = dist[x][y] + 1;
    			q.offer(new int[] {nx, ny});
    		}
    	}
    }
    
    static void eat() {
    	int MN = Integer.MAX_VALUE;
    	
    	for(int i = 0; i < N; i++) {
    		for(int j = 0; j < N; j++) {
    			if(board[i][j] != 0 && board[i][j] < size && dist[i][j] != -1) {
    				MN = Math.min(MN, dist[i][j]);
    			}
    		}
    	}
    	
    	if(MN == Integer.MAX_VALUE) {
    		isCompleted = true;
    		return;
    	}
    	
    	for(int i = 0; i < N; i++) {
    		for(int j = 0; j < N; j++) {
    			if(board[i][j] != 0 && board[i][j] < size && dist[i][j] == MN) {
    				board[i][j] = 0;
    				eaten++;
    				if(eaten == size) {
        				size++;
        				eaten = 0;
        			}
    				distance += dist[i][j];
    				start_x = i;
    				start_y = j;
    				return;
    			}
    		}
    	}
    }
}
