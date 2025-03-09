import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M;
	static int[] arr;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		arr = new int[N];
		
		st = new StringTokenizer(br.readLine());
		
		for(int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		int start = 1;
		int end = Integer.MAX_VALUE - 1;
		
		while(start < end) {
			int mid = (start + end) / 2;
			
			if(solve(mid)) {
				end = mid;
			} else {
				start = mid + 1;
			}
			
		}
		
		System.out.println(start);
	}
	
	static boolean solve(int mid) {
		int cnt = 0;
		int sum = 0;

		for(int i = 0; i < N; i++) {
			if(arr[i] > mid)
				return false;
			
			sum += arr[i];
			
			if(sum > mid) {
				cnt++;
				sum = arr[i];
			}
		}
		
		cnt++;
		
		return cnt <= M;
	}
	
	
}
