import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

public class Main {
    
    static int N, K;
    static Jewel[] jewels;
    static int[] bags;

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        K = Integer.parseInt(st.nextToken());

        jewels = new Jewel[N];
        bags = new int[K];

        // 보석 입력 받기
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int weight = Integer.parseInt(st.nextToken());
            int value = Integer.parseInt(st.nextToken());
            jewels[i] = new Jewel(weight, value);
        }

        // 가방 입력 받기
        for (int i = 0; i < K; i++) {
            bags[i] = Integer.parseInt(br.readLine());
        }

        // 1. 보석을 무게 기준 오름차순 정렬
        Arrays.sort(jewels, (o1, o2) -> o1.weight - o2.weight);

        // 2. 가방을 무게 기준 오름차순 정렬
        Arrays.sort(bags);

        // 3. 우선순위 큐 (최대 힙) 사용: 보석의 "가치(value)"를 기준으로 내림차순 정렬
        PriorityQueue<Integer> pq = new PriorityQueue<>((o1, o2) -> o2 - o1);

        int jewelIdx = 0;
        long answer = 0;

        // 4. 가방을 하나씩 확인하면서 가능한 보석을 추가 후, 가장 가치가 높은 보석을 선택
        for (int i = 0; i < K; i++) {
            while (jewelIdx < N && jewels[jewelIdx].weight <= bags[i]) {
                pq.offer(jewels[jewelIdx].value);
                jewelIdx++;
            }
            if (!pq.isEmpty()) {
                answer += pq.poll(); // 가장 가치(value) 높은 보석 선택
            }
        }

        System.out.println(answer);
    }

    static class Jewel {
        int weight, value;

        Jewel(int weight, int value) {
            this.weight = weight;
            this.value = value;
        }
    }
}

