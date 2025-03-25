import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static int[] path;
	static int[] parent;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		M = Integer.parseInt(br.readLine());
		
		parent = new int[N + 1];
		path = new int[M];
		
		for(int i = 1; i <= N; i++) {
			parent[i] = i;
		}
		
		for(int i = 1; i <= N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j = 1; j <= N; j++) {
				int val = Integer.parseInt(st.nextToken());
				
				if(val == 1)
					union(i, j);
			}
		}
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int i = 0; i < M; i++) {
			path[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i = 0; i < M - 1; i++) {
			int px = find(path[i]);
			int py = find(path[i + 1]);
			
			if(px != py) {
				System.out.println("NO");
				System.exit(0);
			}
		}
		
		System.out.println("YES");
	}
	
	static int find(int x) {
		if(parent[x] == x) return x;
		return parent[x] = find(parent[x]);
	}
	
	static void union(int x, int y) {
		int px = find(x);
		int py = find(y);
		
		if(px < py) parent[py] = px;
		else parent[px] = py;
	}
}
