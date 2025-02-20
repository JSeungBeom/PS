

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main {
	
	static int N, K;
	static int[] dist = new int[200005];
	static Queue<Integer> q = new ArrayDeque<>();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		Arrays.fill(dist, -1);
		
		q.offer(N);
		dist[N] = 0;
		
		while(!q.isEmpty()) {
			int cur = q.poll();

			if(cur == K) {
				System.out.println(dist[cur]);
				break;
			}
			
			
			for(int nxt : new int[] { cur + 1, cur - 1, cur * 2 } ) {
				if(nxt < 0 || nxt > 200000) continue;
				if(dist[nxt] >= 0) continue;		
				
				dist[nxt] = dist[cur] + 1;
				q.offer(nxt);
			}
			
		}
	}

}
