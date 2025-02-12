import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int cnt; 
	static int N, r, c;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		r = Integer.parseInt(st.nextToken());
		c = Integer.parseInt(st.nextToken());
		
		System.out.println(solve(N, r, c)); // 3, 3, 4
	} 
	
	static int solve(int N, int y, int x) {
		if(N == 0)
			return 0;
		
		
		int half = 1 << (N - 1);
		
		if(y < half && x < half) {
			return solve(N - 1, y, x);
		}
		else if(y < half && x >= half) {
			return half * half + solve(N - 1, y, x - half);
		}
		else if(y >= half && x < half) {
			return 2 * half * half + solve(N - 1, y - half, x);
		}
		else {
			return 3 * half * half + solve(N - 1, y - half, x - half);
		}
		
	
	}
}

