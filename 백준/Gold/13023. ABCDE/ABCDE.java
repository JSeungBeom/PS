import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static List<List<Integer>> adj = new ArrayList<>();
	static boolean[] vis;	
	static boolean chk;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		for(int i = 0; i < N; i++) {
			adj.add(new ArrayList<>());
		}
		
		for(int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			
			adj.get(a).add(b);
			adj.get(b).add(a);
		}
		
		for(int i = 0; i < N; i++) {
			vis = new boolean[N];
			DFS(i, 0);
			
			if(chk) {
				System.out.println(1);
				return;
			}
		}
		
		System.out.println(0);
	}
	
	static void DFS(int cur, int cnt) {			
		if(cnt == 4) {
			chk = true; return;
		}
		
		vis[cur] = true;
		
		for(int nxt : adj.get(cur)) {
			if(vis[nxt]) continue;
			DFS(nxt, cnt + 1);
		}
		
		vis[cur] = false;
	}
}
