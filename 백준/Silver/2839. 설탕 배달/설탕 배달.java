import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        int[] dp = new int[5005];

        for(int i = 1; i <= 5000; i++)
            dp[i] = -1;

        dp[0] = 0; dp[3] = 1;

        for(int i = 5; i <= N; i++){
            dp[i] = 0x7fffffff;

            if(dp[i - 5] >= 0)
                dp[i] = Math.min(dp[i - 5] + 1, dp[i]);
            if(dp[i - 3] >= 0)
                dp[i] = Math.min(dp[i - 3] + 1, dp[i]);

            if(dp[i] == 0x7fffffff)
                dp[i] = -1;
        }

        System.out.print(dp[N]);
    }
}
