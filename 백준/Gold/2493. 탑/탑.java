import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int[] tower = new int[N + 1];
		Deque<int[]> stack = new ArrayDeque<>();
		
		stack.push(new int[] {0, Integer.MAX_VALUE});
		
		for(int i = 1; i <= N; i++) {
			tower[i] = Integer.parseInt(st.nextToken());
			
			while(!stack.isEmpty() && stack.peek()[1] < tower[i]) {
				stack.pop();
			}
			
			System.out.print(stack.peek()[0] + " ");
			
			stack.push(new int[] {i, tower[i]});
		}
	}

}
