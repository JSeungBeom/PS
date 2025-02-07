import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		
		System.out.print("<");
		
		Deque<Integer> dq = new LinkedList<>();
		
		int cnt = 0;
		
		for(int i = 1; i <= N; i++) {
			dq.add(i);
		}
		
		while(!dq.isEmpty()) {
			if(dq.size() == 1) {
				System.out.print(dq.getFirst());
				break;
			}
			
			cnt++;
			
			if(cnt != K) {
				dq.addLast(dq.getFirst());
				dq.removeFirst();
			} else {
				System.out.print(dq.getFirst() + ", ");
				dq.removeFirst();
				cnt = 0;
			}
		}
		
		System.out.print(">");
		
	}

}
