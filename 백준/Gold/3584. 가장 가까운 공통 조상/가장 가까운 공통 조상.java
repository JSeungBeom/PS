import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {
	
	static int T, N;
	static int[] parent;
	static int nodeA, nodeB;
	static HashSet<Integer> set;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		T = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < T; i++) {
			N = Integer.parseInt(br.readLine());
			parent = new int[N + 1];
			set = new HashSet<>();
			
			for(int j = 0; j < N - 1; j++) {
				StringTokenizer st = new StringTokenizer(br.readLine());
				
				int A = Integer.parseInt(st.nextToken());
				int B = Integer.parseInt(st.nextToken());
				
				parent[B] = A;
			}
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			
			nodeA = Integer.parseInt(st.nextToken());
			nodeB = Integer.parseInt(st.nextToken());	
			
			int cur = nodeA;
			
			while(cur != 0) {
				set.add(cur);
				
				cur = parent[cur];
			}
			
			cur = nodeB;
			
			while(cur != 0) {
				if(set.contains(cur)) {
					System.out.println(cur);
					break;
				}
				
				
				cur = parent[cur];
			}
		}
		
	
		
	}
}
