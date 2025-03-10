import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int N, remove, root, ans;
	static List<List<Integer>> childs = new ArrayList<>();
	static boolean[] vis;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		vis = new boolean[N];
		
		for(int i = 0; i <= N; i++) {
			childs.add(new ArrayList<Integer>());
		}
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int i = 0; i < N; i++) {
			int parent = Integer.parseInt(st.nextToken());
			
			if(parent == -1) {
				root = i; continue;
			}
			
			childs.get(parent).add(i);
		}
		
		remove = Integer.parseInt(br.readLine());
		
		DFS(root);
		
		System.out.println(ans);
	}
	
	static void DFS(int root) {
		vis[root] = true;
			
		if(root == remove) return;
		
		
		int size = childs.get(root).size();
		
		for(int nxt : childs.get(root)) {
			if(nxt == remove) {
				size--; break;
			}
		}
		
		
		if(size == 0) {
			ans++;
			return;
		}
		
		for(int nxt : childs.get(root)) {
			if(vis[nxt]) continue;
			
			DFS(nxt);
		}
	}
	
}
