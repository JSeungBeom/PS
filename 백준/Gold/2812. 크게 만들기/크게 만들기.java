import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;
import java.util.StringTokenizer;

public class Main {

	static int N, K;
	static String s;
	static StringBuilder sb = new StringBuilder();
	static Stack<Character> stack = new Stack<>();
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	
    	StringTokenizer st = new StringTokenizer(br.readLine());
    	
    	N = Integer.parseInt(st.nextToken());
    	K = Integer.parseInt(st.nextToken());
    	
    	s = br.readLine();
    	int cnt = 0;
    	
    	for(int i = 0; i < N; i++) {
    		while(!stack.isEmpty() && 
    				cnt < K &&
    				s.charAt(i) > stack.peek()) {
    			cnt++;
    			stack.pop();
    		}
    		
    		stack.push(s.charAt(i));
    	}
    	
    	while(cnt < K) {
    		stack.pop(); cnt++;
    	}
    	
    	while(!stack.isEmpty()) {
    		sb.append(stack.pop());
    	}
    	
    	sb.reverse();
    	
    	if(sb.length() == 0) 
    		System.out.println(0);	
    	else
    		System.out.println(sb);
	}
	
}
