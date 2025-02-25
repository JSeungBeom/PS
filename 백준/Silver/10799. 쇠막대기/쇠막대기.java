import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

public class Main {

	static char[] input;
	static Stack<Character> st = new Stack<>();
	static int ans;
	
	public static void main(String[] args) throws Exception {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    	input = br.readLine().toCharArray();
    	boolean is_laser = true;
 
    	for(int i = 0; i < input.length; i++) {
    		if(input[i] == '(') {
    			is_laser = true;
    			st.push('(');
    		}
    		else if(is_laser && input[i] == ')'){
    			is_laser = false;
    			st.pop();
    			ans += st.size();
    		}
    		else {
    			st.pop(); ans++;
    		}
    	}
    	
    	System.out.println(ans);
	}
	
}
