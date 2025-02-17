import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main {

	static int N, answer;
	static boolean[] isused1 = new boolean[20];
	static boolean[] isused2 = new boolean[50];
	static boolean[] isused3 = new boolean[50];
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		N = Integer.parseInt(br.readLine());
		
		backTracking(0);
		
		System.out.println(answer);
	}
	
	static void backTracking(int cur) {
		if(cur == N) {
			answer++;
			return;
		}
		
		
		for(int i = 0; i < N; i++) {
			if(isused1[i] || isused2[cur + i] || isused3[cur - i + N - 1]) continue;
			
			isused1[i] = true;
			isused2[cur + i] = true;
			isused3[cur - i + N - 1] = true;
			backTracking(cur + 1);
			isused1[i] = false;
			isused2[cur + i] = false;
			isused3[cur - i + N - 1] = false;
			
		}
	}
	
	
}

