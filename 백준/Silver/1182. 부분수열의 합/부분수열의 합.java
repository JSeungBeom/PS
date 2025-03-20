import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, S;
	static int[] arr;
	static boolean[] vis;
	static int ans;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		S = Integer.parseInt(st.nextToken());
		
		arr = new int[N];
		vis = new boolean[N];
		
		st = new StringTokenizer(br.readLine());
		
		for(int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		subset(0);
		
		System.out.println(ans);
	}
	
	static void subset(int K) {
		if(K == N) {
			int sum = 0;
			int cnt = 0;
			
			for(int i = 0; i < N; i++) {
				if(vis[i]) {
					cnt++;
					sum += arr[i];
				}
			}
			
			if(sum == S && cnt != 0) ans++;
			
			return;
		}
		
		vis[K] = true;
		subset(K + 1);
		
		vis[K] = false;
		subset(K + 1);
	}
}
