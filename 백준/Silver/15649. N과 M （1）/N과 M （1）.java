import java.util.*;
import java.io.*;

public class Main {

    static boolean[] vis;
    static int[] arr;
    static int N;
    static int M;

    static void back_tracking(int n, int k){
        if(n == k){
            for(int i = 0; i < n; i++){
                System.out.print(arr[i] + " ");
            }

            System.out.println();

            return;
        }

        for(int i = 1; i <= N; i++){
            if(vis[i]) continue;

            vis[i] = true;
            arr[n] = i;
            back_tracking(n + 1, k);
            vis[i] = false;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        vis = new boolean[N + 1];
        arr = new int[N + 1];

        back_tracking(0, M);

    }
}
