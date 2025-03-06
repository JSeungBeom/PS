import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int N, M;
	static List<int[]> A = new ArrayList<>();
	static List<int[]> B = new ArrayList<>();
	static List<Integer> ans = new ArrayList<>();
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int i = 0; i < N; i++) {
			int value = Integer.parseInt(st.nextToken());
			A.add(new int[] {value, i});
		}
		
		M = Integer.parseInt(br.readLine());
		
		st = new StringTokenizer(br.readLine());
		
		for(int i = 0; i < M; i++) {
			int value = Integer.parseInt(st.nextToken());
			B.add(new int[] {value, i});
		}
		
		Collections.sort(A, (a1, a2) -> (a1[0] == a2[0]) ? a1[1] - a2[1] : a2[0] - a1[0]);
		Collections.sort(B, (b1, b2) -> (b1[0] == b2[0]) ? b1[1] - b2[1] : b2[0] - b1[0]);

		int aidx = 0, bidx = 0, alimit = -1, blimit = -1;
		
		while(aidx < N && bidx < M) {
			if(A.get(aidx)[0] == B.get(bidx)[0]) {
				if(alimit > A.get(aidx)[1]) aidx++;
				else if(blimit > B.get(bidx)[1]) bidx++;
				else {
					alimit = A.get(aidx)[1];
					blimit = B.get(bidx)[1];
					ans.add(A.get(aidx)[0]);
					aidx++;
					bidx++;
				}
			}
			else if(A.get(aidx)[0] > B.get(bidx)[0]) {
				aidx++;
			} else {
				bidx++;
			}
		}
		
		System.out.println(ans.size());
		
		for(int num : ans) {
			System.out.print(num + " ");
		}
	}
}
