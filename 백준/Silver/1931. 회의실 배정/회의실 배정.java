import java.util.*;
import java.io.*;

public class Main {

    private final int start_time;
    private final int end_time;

    public Main(int start_time, int end_time){
        this.start_time = start_time;
        this.end_time = end_time;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(br.readLine());

        Main[] arr = new Main[N];

        for(int i = 0; i < N; i++){
            StringTokenizer st = new StringTokenizer(br.readLine());

            int start_time = Integer.parseInt(st.nextToken());
            int end_time = Integer.parseInt(st.nextToken());

            arr[i] = new Main(start_time, end_time);
        }

        Arrays.sort(arr, new Comparator<Main>() {
            @Override
            public int compare(Main m1, Main m2){
                if(m1.end_time == m2.end_time)
                    return m1.start_time - m2.start_time;
                return m1.end_time - m2.end_time;
            }
        });

        int ans = 1;
        int en = arr[0].end_time;

        if(N == 1) {
            System.out.println(ans); return;
        }

        for(int i = 1; i < N; i++){
            if(arr[i].start_time >= en){
                ans++;
                en = arr[i].end_time;
            }
        }

        System.out.println(ans);
    }
}
