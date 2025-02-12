import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {
	
	static int N;

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		
		int answer = 0;
		
		while(true) {
			if(N < 0) {
				System.out.println(-1); // 3과 5로 만들지 못하는 경우
				break;
			}
			
			// N을 5로 나누어 떨어지는지
			if(N % 5 == 0) {
				System.out.println(answer + N / 5);
				break;
			}
			
			N -= 3;
			answer++;
		}
	}

}