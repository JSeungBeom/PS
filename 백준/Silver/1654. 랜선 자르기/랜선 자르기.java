import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int[] lan;
	static int K, N;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		lan = new int[1000005];
		
		K = Integer.parseInt(st.nextToken());
		N = Integer.parseInt(st.nextToken());
		
		for(int i = 0; i < K; i++) {
			lan[i] = Integer.parseInt(br.readLine());
		}
		
		long start = 1;
		long end = Integer.MAX_VALUE;
		
		while(start < end) {
			long mid = (start + end + 1) / 2;
			
			if(binary_search(mid)) start = mid;
			else end = mid - 1;
		}
		
		System.out.println(start);
	}
	
	static boolean binary_search(long mid) {
		long sum = 0;
		
		for(int i = 0; i < K; i++) {
			sum += (lan[i] / mid);
		}
		
		return sum >= N;
	}

}
