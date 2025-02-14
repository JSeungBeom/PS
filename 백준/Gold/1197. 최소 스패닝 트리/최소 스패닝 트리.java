import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {

	static int V, E;
	static List<List<int[]>> adj = new ArrayList<>();
	static boolean[] vis;
	static PriorityQueue<int[]> pq = new PriorityQueue<>((v1, v2) -> v1[1] - v2[1]);
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		V = Integer.parseInt(st.nextToken());
		E = Integer.parseInt(st.nextToken());
		
		vis = new boolean[V + 1];
		for(int i = 0; i <= V; i++) {
			adj.add(new ArrayList<int[]>());
		}
		
		for(int i = 0; i < E; i++) {
			st = new StringTokenizer(br.readLine());
			
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			int c = Integer.parseInt(st.nextToken());
			
			adj.get(u).add(new int[] {v, c});
			adj.get(v).add(new int[] {u, c});			
		}
		
		pq.offer(new int[] {1, 0});
		
		int cnt = 0;
		int sum = 0;
		
		while(!pq.isEmpty()) {
			int[] cur = pq.poll();
			int v = cur[0];
			int c = cur[1];
			
			if(vis[v]) continue;
			
			vis[v] = true;
			sum += c;
			cnt++;
			
			if(cnt == V) break;
			
			for(int[] nxt : adj.get(v)) {
				if(vis[nxt[0]]) continue;
				pq.offer(nxt);
			}
		}
		
		System.out.println(sum);
		
	}
}

