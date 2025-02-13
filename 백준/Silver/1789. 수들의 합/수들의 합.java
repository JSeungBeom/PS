import java.io.BufferedReader;
import java.io.InputStreamReader;

public class Main {

	static long S;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	
		S = Long.parseLong(br.readLine());
		
		int decre = 1;
		
		while(true) {
			
			if((S -= decre) < 0) {
				break;
			}
			
			decre++;
		}
		
		System.out.println(decre - 1);
	}
}

