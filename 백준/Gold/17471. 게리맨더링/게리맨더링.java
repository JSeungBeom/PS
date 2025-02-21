import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

import javax.swing.plaf.synth.SynthOptionPaneUI;
public class Main {
	
	static int N;
	static List<List<Integer>> adj = new ArrayList<>();
	static boolean[] select;
	static boolean[] visit;
	static int[] human;
	
	static Queue<Integer> q = new ArrayDeque<>();
	static int num1, num2;
	static int MN = Integer.MAX_VALUE;
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	N = Integer.parseInt(br.readLine());
    	select = new boolean[N + 1];
    	human = new int[N + 1];
    	StringTokenizer st = new StringTokenizer(br.readLine());
    		
    	for(int j = 1; j <= N; j++) {
			human[j] = Integer.parseInt(st.nextToken());
		}
    	
    	for(int i = 0; i <= N; i++) {
    		adj.add(new ArrayList<>());
    	}
    	
    	for(int i = 1; i <= N; i++) {
    		st = new StringTokenizer(br.readLine());
    		
			int num = Integer.parseInt(st.nextToken());
    		
			for(int j = 1; j <= num; j++) {
				int nxt = Integer.parseInt(st.nextToken());

				adj.get(i).add(nxt);
			}
    	}
    	
    	makeSubset(0);
    	if(MN == Integer.MAX_VALUE)
    		System.out.println(-1);
    	else
    		System.out.println(MN);
    	
	}
	
	static void makeSubset(int K) {
		if(N + 1 == K) {
			if(bfs()) {
				MN = Math.min(MN, Math.abs(num1 - num2));
			}
			return;
		}
		
		select[K] = true;
		makeSubset(K + 1);
		
		select[K] = false;
		makeSubset(K + 1);
	}
	
	static boolean bfs() {
		boolean isCon1 = true;
		boolean isCon2 = true;
		
		num1 = 0;
		num2 = 0;
		int cnt1 = 0;
		int cnt2 = 0;
		
    	visit = new boolean[N + 1];
    	
    	
		for(int i = 1; i <= N; i++) {
			if(!select[i] || visit[i]) continue;
			
			cnt1++;
			q.offer(i);
			visit[i] = true;

			while(!q.isEmpty()) {
				int cur = q.poll();
				num1 += human[cur];
	
				for(int nxt : adj.get(cur)) {
					if(visit[nxt]) continue;
					if(!select[nxt]) continue;
					
					q.offer(nxt);
					visit[nxt] = true;
					
				}
			}
		}
		
		for(int i = 1; i <= N; i++) {
			if(select[i] || visit[i]) continue;
			
			q.offer(i);
			visit[i] = true;
			cnt2++;

			while(!q.isEmpty()) {
				int cur = q.poll();
				num2 += human[cur];
				
				for(int nxt : adj.get(cur)) {
					if(visit[nxt]) continue;
					if(select[nxt]) continue;
					q.offer(nxt);
					visit[nxt] = true;
				}
			}
		}
	
		
		if(cnt1 != 1 || cnt2 != 1)
			return false;
		
		for(int i = 1; i <= N; i++) {
			if(!visit[i]) {
				return false;
			}
		}
		
		return true;
		
		
	}
	
}
