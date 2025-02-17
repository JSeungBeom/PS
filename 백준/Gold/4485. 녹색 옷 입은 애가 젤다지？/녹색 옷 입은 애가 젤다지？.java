import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	
	static int N;
	static int[][] board;
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	static int[][] dist;
	static final int MX = Integer.MAX_VALUE;
	static PriorityQueue<int[]> pq = new PriorityQueue<>((v1, v2) -> v1[2] - v2[2]);
	
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	int num = 1;

        while(true) {
        	N = Integer.parseInt(br.readLine());
        	
        	if(N == 0) break;
        	
        	board = new int[N][N];
        	dist = new int[N][N];
        	for(int i = 0; i < N; i++) {
        		StringTokenizer st = new StringTokenizer(br.readLine());
        		
        		for(int j = 0; j < N; j++) {
        			board[i][j] = Integer.parseInt(st.nextToken());
        		}
        	}
        	
        	for(int i = 0; i < N; i++) {
        		Arrays.fill(dist[i], MX);
        	}
        	
        	dist[0][0] = board[0][0];
        	pq.offer(new int[] {0, 0, dist[0][0]});
        
        	
        	while(!pq.isEmpty()) {
        		int[] cur = pq.poll();
        		
        		int x = cur[0];
        		int y = cur[1];
        		int c = cur[2];
        		
        		if(dist[x][y] < c) continue;
        		
        		for(int dir = 0; dir < 4; dir++) {
        			int nx = x + dx[dir];
        			int ny = y + dy[dir];
        			
        			if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
        			
        			if(dist[nx][ny] > board[nx][ny] + c) {
        				dist[nx][ny] = board[nx][ny] + c;
        				
        				pq.offer(new int[] {nx, ny, dist[nx][ny]});
        			}
        		}
        	
        	}
        	
        	System.out.println("Problem " + num + ": " + dist[N - 1][N - 1]);
        	num++;
        }
            
    }
}
