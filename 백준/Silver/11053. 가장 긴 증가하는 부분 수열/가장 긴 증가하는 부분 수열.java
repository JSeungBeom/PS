import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
public class Main {

	static int N;
	static int[] dp;
	static int[] arr;
	
    public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	N = Integer.parseInt(br.readLine());
    	
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	
    	arr = new int[N + 1];
    	dp = new int[N + 1];
    	
    	for(int i = 1; i <= N; i++) {
    		arr[i] = Integer.parseInt(st.nextToken());
    	}
    	
    	Arrays.fill(dp, 1);
    	for(int i = 1; i <= N; i++) {
    		for(int j = 1; j <= i; j++) {
    			if(arr[i] > arr[j]) {
    				dp[i] = Math.max(dp[i], dp[j] + 1);
    			}
    		}
    	}
    	    	
    	System.out.println(Arrays.stream(dp).max().orElse(0));
    }
}
