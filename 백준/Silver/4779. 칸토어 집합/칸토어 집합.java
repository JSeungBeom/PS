import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static int N;
	static StringBuilder sb = new StringBuilder();
	static String s;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		
		while((s = br.readLine()) != null && !s.isEmpty()) {
			N = Integer.parseInt(s);
			
			int cur = (int)Math.pow(3, N);
			
			sb.setLength(0);
			
			for(int i = 0; i < cur; i++) {
				sb.append('-');
			}
			
			makeBlank(cur, 0, cur);
			
			System.out.println(sb);
		}
	}
	
	static void makeBlank(int N, int st, int en) {
		if(N == 1)
			return;
		
		// Divide
		makeBlank(N / 3, st, st + N / 3);
		makeBlank(N / 3, en - N / 3, en);
		
		for(int i = st + N / 3; i < en - N / 3; i++) {
			sb.setCharAt(i, ' ');
		}
	}
	
}

