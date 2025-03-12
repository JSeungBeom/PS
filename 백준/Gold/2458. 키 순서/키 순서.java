import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M;
	static List<List<Integer>> adj = new ArrayList<>();
	static List<List<Integer>> reverse_adj = new ArrayList<>();
	static boolean[] vis;
	static int ans;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		for(int i = 0; i <= N; i++) {
			adj.add(new ArrayList<Integer>()); 
			reverse_adj.add(new ArrayList<Integer>()); 
		}
		
		for(int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			
			int u = Integer.parseInt(st.nextToken());
			int v = Integer.parseInt(st.nextToken());
			
			adj.get(u).add(v);
			reverse_adj.get(v).add(u);
		}
			
		vis = new boolean[N + 1];
		
		for(int i = 1; i <= N; i++) {
			Arrays.fill(vis, false);
			
			DFS(i, adj);
			DFS(i, reverse_adj);
			
			ans += check();
		}
		
		System.out.println(ans);
	}
	
	static int check() {
		for(int i = 1; i <= N; i++) {
			if(!vis[i]) return 0;
		}
		
		return 1;
	}
	
	static void DFS(int cur, List<List<Integer>> adj) {
		vis[cur] = true;
		
		for(int nxt : adj.get(cur)) {
			if(vis[nxt]) continue;
			
			DFS(nxt, adj);
		}
	}
}
