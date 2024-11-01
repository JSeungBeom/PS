import java.util.*;
import java.io.*;

public class Main {

    static boolean solve(int N, int M, int[] arr, long mid) {
        long sum = 0;

        for(int i = 0; i < N; i++){
            if(arr[i] - mid >= 0)
                sum += (arr[i] - mid);
        }

        return sum >= M;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        st = new StringTokenizer(br.readLine());
        int[] arr = new int[N];

        for(int i = 0; i < N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        long start = 0;
        long end = 1000000000;
        long mid = 0;

        while(start < end){
            mid = (start + end + 1)/ 2;

            if(solve(N, M, arr, mid))
                start = mid;
            else
                end = mid - 1;
        }

        System.out.print(start);
    }
}
