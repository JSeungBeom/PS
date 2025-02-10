// nCr 공식을 
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
		static boolean[] vis = new boolean[10];
		static int[] tgt = new int[10];
		static int N, M;
		
		public static void main(String[] args) throws IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
	
		perm(0);
		
    }
		
		static void perm(int idx) {
			if(idx == M) {
				for (int i = 0; i < M; i++) {
					System.out.print(tgt[i] + " ");
				}
				System.out.println();
				
				return;
			}
			
			for(int i = 1; i <= N; i++) {
				if(vis[i]) continue;
				
				tgt[idx] = i;
				vis[i] = true;
				perm(idx + 1);
				vis[i] = false;
			}
		}
}