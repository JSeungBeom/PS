import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M;
	static List<int[]> edges = new ArrayList<>();
	static int[] parent;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        N = Integer.parseInt(br.readLine());
        M = Integer.parseInt(br.readLine());
        for(int i = 0; i < M; i++) {
        	StringTokenizer st = new StringTokenizer(br.readLine());
            
        	int u = Integer.parseInt(st.nextToken());
        	int v = Integer.parseInt(st.nextToken());
        	int c = Integer.parseInt(st.nextToken());
        	
        	edges.add(new int[] {u, v, c});
        }
        
        parent = new int[N + 1];
        
        Collections.sort(edges, (e1, e2) -> e1[2] - e2[2]);
        
        for(int i = 1; i <= N; i++)
        	parent[i] = i;
        
        int cnt = 0;
        int sum = 0;
        
        for(int i = 0; i < M; i++) {
        	int u = edges.get(i)[0];
        	int v = edges.get(i)[1];
        	int c = edges.get(i)[2];
        	
        	if(union(u, v)) {
        		sum += c;
        		cnt++;
        	}
        	
        	if(cnt == N - 1) break;
        }
        
        System.out.println(sum);
        
    }
    
    static int find(int x) {
    	if(parent[x] == x) return x;
    	return parent[x] = find(parent[x]);
    }
    
    static boolean union(int x, int y) {
    	int px = find(x);
    	int py = find(y);
    	
    	if(px == py) return false;
    	if(px < py) parent[px] = parent[py];
    	else parent[py] = parent[px];
    	
    	return true;
    }
}
