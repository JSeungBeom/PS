import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.Objects;
import java.util.StringTokenizer;

public class Main {
	
	static int T, N;
	static Employee[] score;
	
	static class Employee {
		int paper_rank;
		int interview_rank;
		
		Employee(int paper_rank, int interview_rank){
			this.paper_rank = paper_rank;
			this.interview_rank = interview_rank;
		}
	}

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		T = Integer.parseInt(br.readLine());
		
		for(int tc = 0; tc < T; tc++) {
			N = Integer.parseInt(br.readLine());
			
			score = new Employee[N];
			
			for(int i = 0; i < N; i++) {
				StringTokenizer st = new StringTokenizer(br.readLine());

				int paper_rank = Integer.parseInt(st.nextToken());
				int interview_rank = Integer.parseInt(st.nextToken());
				
				score[i] = new Employee(paper_rank, interview_rank);
			}			
				
			Arrays.sort(score, (o1, o2) -> o1.paper_rank - o2.paper_rank);
			
			int answer = 1; // 서류 1등 합격
			int base_interview = score[0].interview_rank; 
			
			for(int i = 0; i < N; i++) {
				if(score[i].interview_rank < base_interview) {
					answer++;
					base_interview = score[i].interview_rank;
				}
			}
			
			
			System.out.println(answer);
			
		}
	}
	
}
