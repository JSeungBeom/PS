import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int N;
	static int[] arr;
	static int MN = Integer.MAX_VALUE;
	static int[] ans;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		arr = new int[N];
		ans = new int[2];
		
		for(int i = 0; i < N; i++) {
			arr[i] = Integer.parseInt(st.nextToken());
		}
		
		Arrays.sort(arr);
		
		for(int i = 0; i < N - 1; i++) {
			if(MN > Math.abs(arr[i] + arr[i + 1])) {
				MN = Math.abs(arr[i] + arr[i + 1]);
				ans[0] = arr[i]; ans[1] = arr[i + 1];
			}
			
			int idx1 = -(Arrays.binarySearch(arr, i + 1, N, -arr[i]) + 1);
			int idx2 = Arrays.binarySearch(arr, i + 1, N, -arr[i]);
			
			if(idx1 - 1 < N && idx1 - 1 >= 0 && idx1 - 1 != i) {
				if(MN > Math.abs(arr[i] + arr[idx1 - 1])) {
					MN = Math.abs(arr[i] + arr[idx1 - 1]);
					ans[0] = arr[i]; ans[1] = arr[idx1 - 1];
				}
			}
			
			if(idx1 < N && idx1 >= 0 && idx1 != i) {
				if(MN > Math.abs(arr[i] + arr[idx1])) {
					MN = Math.abs(arr[i] + arr[idx1]);
					ans[0] = arr[i]; ans[1] = arr[idx1];
				}
			}
			
			if(idx2 < N && idx2 >= 0 && idx2 != i) {
				if(MN > Math.abs(arr[i] + arr[idx2])) {
					MN = Math.abs(arr[i] + arr[idx2]);
					ans[0] = arr[i]; ans[1] = arr[idx2];
				}
			}
		}
		
		Arrays.sort(ans);
		
		for(int answer : ans)
			System.out.print(answer + " ");
	}
	
}
