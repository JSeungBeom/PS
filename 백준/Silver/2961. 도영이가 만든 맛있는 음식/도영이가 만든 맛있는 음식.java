import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int[] S = new int[15];
	static int[] B = new int[15];
	static boolean[] chk = new boolean[15];
	static long MIN = Long.MAX_VALUE;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		
		for(int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			S[i] = Integer.parseInt(st.nextToken());
			B[i] = Integer.parseInt(st.nextToken());
		}
		
		subset(0);
		
		System.out.println(MIN);
	}
	
	static void subset(int idx) {
		if(idx == N) {
			MIN = calc_min();
			return;
		}
		
		chk[idx] = true;
		subset(idx + 1);
		
		chk[idx] = false;
		subset(idx + 1);
	}
	
	static long calc_min() {
		long s_mul = 1;
		long b_plus = 0;
		
		for(int i = 0; i < N; i++) {
			if(chk[i]) {
				s_mul *= S[i];
				b_plus += B[i];
			}
		}
		
		if(s_mul == 1 && b_plus == 0) return MIN;
			
			
		return MIN > Math.abs(s_mul - b_plus) ? Math.abs(s_mul - b_plus) : MIN; 
	}

}
