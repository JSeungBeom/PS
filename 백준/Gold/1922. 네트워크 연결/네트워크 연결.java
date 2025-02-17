import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M;
	static List<List<int[]>> adj = new ArrayList<>();
	static boolean[] vis;
	static PriorityQueue<int[]> pq = new PriorityQueue<>((o1, o2) -> o1[1] - o2[1]);
	
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        
        for(int i = 0; i <= N; i++) {
        	adj.add(new ArrayList<>());
        }
        
        vis = new boolean[N + 1];
        
        for(int i = 0; i < M; i++) {
        	StringTokenizer st = new StringTokenizer(br.readLine());
            
        	int u = Integer.parseInt(st.nextToken());
        	int v = Integer.parseInt(st.nextToken());
        	int c = Integer.parseInt(st.nextToken());
        	
        	adj.get(u).add(new int[] {v, c});
        	adj.get(v).add(new int[] {u, c});
        }
        
        pq.offer(new int[] {1, 0});
        
        int sum = 0;
        int cnt = 0;
        
        while(!pq.isEmpty()) {
        	int[] cur = pq.poll();
        	int v = cur[0];
        	int c = cur[1];
        	
        	if(vis[v]) continue;
        	
        	vis[v] =true;
        	sum += c;
        	cnt++;
        	
        	if(cnt == N) break;
        	
        	for(int[] nxt : adj.get(v)) {
        		if(vis[nxt[0]]) continue;
        		
        		pq.offer(nxt);
        	}
        }
        
        System.out.println(sum);
            
    }
}
