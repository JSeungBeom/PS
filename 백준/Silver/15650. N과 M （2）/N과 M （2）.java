import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static boolean[] vis;
	static int[] arr;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		vis = new boolean[N];
		arr = new int[M];
		
		perm(0, 0);
	}
	
	static void perm(int K, int st) {
		if(M == K) {
			for(int i = 0; i < M; i++) {
				System.out.print(arr[i] + " ");
			}
			System.out.println();
			return;
		}
		
		for(int i = st; i < N; i++) {
			if(vis[i]) continue;
			
			arr[K] = i + 1;
			vis[i] = true;
			perm(K + 1, i);
			vis[i] = false;
		}
	}
}
