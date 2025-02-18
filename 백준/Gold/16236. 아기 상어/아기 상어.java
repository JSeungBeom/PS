
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

// 시뮬레이션
public class Main {

	static int N, sx, sy, sSize, sEatCnt, ans;
	static int[][] map;
	
	// bfs
	static Queue<Node> queue = new ArrayDeque<>();
	static boolean[][] vis;
	// delta
	static int[] dx = {1, 0, -1, 0};
	static int[] dy = {0, 1, 0, -1};
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		
		map = new int[N][N];
		vis = new boolean[N][N];
		
		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			for(int j = 0; j < N; j++) {
				int n = Integer.parseInt(st.nextToken());
				if(n == 9) {
					sx = i; 
					sy = j;
				}
				
				map[i][j] = n;
			}
		}
		
		// 시뮬레이션
		sSize = 2;
		
		// 반복횟수 미정 <= while
		while(true) {
			// 최단거리의 물고기를 먹었으면 먹는 과정에서 이동한 거리를 return, 못 먹으면 0 리턴
			int cnt = bfs();
			if(cnt == 0) break;
			ans += cnt;
			
		}
		
		System.out.println(ans);
	}
	
	// 최단거리의 물고기를 먹으려고 시도
	// 성공 : 이동한 거리(시간) 리턴
	// 실패 : 0 리턴
	static int bfs() {
		// 먹이 후보
		int minDis = Integer.MAX_VALUE; // bfs() 과정에서 먹을 수 있는 물고기를 찾으면 갱신
		int minX = Integer.MAX_VALUE;
		int minY = Integer.MAX_VALUE;
		
		// visit 초기화
		for(int i = 0; i < N; i++) {
			Arrays.fill(vis[i], false);
		}
		
		// 현재 아기상어의 위치에서부터 시작
		vis[sx][sy] = true;
		queue.offer(new Node(sx, sy, 0));
		
		while(!queue.isEmpty()) {
			Node node = queue.poll();
			int x = node.x;
			int y = node.y;
			int d = node.d; // 상어위치부터 탐색해 온 거리
			
			// 먹을 수 있는 물고기를 만나면 
			if(map[x][y] < sSize && map[x][y] != 0) {
				if(d < minDis) { // 거리가 더 작은 
					minDis = d;
					minX = x;
					minY = y;
				} else if(d == minDis) { // 거리가 같으면
					if(x < minX) {
						minDis = d;
						minX = x;
						minY = y;
					} else if(x == minX) {
						if(y < minY) {
							minDis = d;
							minX = x;
							minY = y;	
						}
					}
				}
			} // if
			
			// 가지치기
			if(d + 1 >= minDis) continue;
			
			// 4방탐색
			for(int dir = 0; dir < 4; dir++) {
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				
				if(nx < 0 || nx >= N || ny < 0 || ny >= N || vis[nx][ny] || map[nx][ny] > sSize) continue;
				
				vis[nx][ny] = true;
				queue.offer(new Node(nx, ny, node.d + 1));
			} // for
		} // while
		
		// 물고기를 먹는 작업 성공/실패
		if(minDis == Integer.MAX_VALUE) return 0; // 먹이를 찾지 못한 경우
		else { // 물고기를 찾아 먹은 경우 후처리
			sEatCnt++;
			if(sEatCnt == sSize) {
				sSize++;
				sEatCnt = 0;
			}
			map[minX][minY] = 0; // 먹은 물고기 자리
			map[sx][sy] = 0; // 상어가 출발한 자리
			
			sx = minX;
			sy = minY;
		}
		
		return minDis;
	}

	static class Node {
		int x, y, d; // d : 거리
		
		Node(int x, int y, int d){
			this.x = x;
			this.y = y;
			this.d = d;
		}
	}
}
