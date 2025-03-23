import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static int N, ans;
	static PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[1] == o2[1] ? o1[0] - o2[0] : o2[1] - o1[1]);
	static boolean[] vis = new boolean[1001];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			int d = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			
			pq.add(new int[] {d, w});
		}
		
		while(!pq.isEmpty()) {
			int[] cur = pq.poll();
			
			for(int i = cur[0]; i >= 1; i--) {
				if(vis[i]) continue;
				
				vis[i] = true;
				ans += cur[1]; 
				break;
			}
			
		}
		
		System.out.println(ans);
	}
}
