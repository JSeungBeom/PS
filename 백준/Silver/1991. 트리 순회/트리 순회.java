import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static int[] leftChild;
	static int[] rightChild;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		leftChild = new int[26]; // 왼쪽 자식 담을 배열
		rightChild = new int[26]; // 오른쪽 자식 담을 배열
		
		for(int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			// 루트
			char root = st.nextToken().charAt(0);
			char lc = st.nextToken().charAt(0);
			char rc = st.nextToken().charAt(0);
			
			// 왼쪽 자식
			if(lc != '.') {
				leftChild[root - 'A'] = lc - 'A'; 
			}
			
			// 오른쪽 자식
			if(rc != '.') {
				rightChild[root - 'A'] = rc - 'A';
			}
		}
		
		preOrder(0);
		System.out.println();
		inOrder(0);
		System.out.println();
		postOrder(0);
		
	}
	
	// 전위 순회
	static void preOrder(int cur) {
		System.out.print((char)(cur + 'A')); // 루트
		
		if(leftChild[cur] != 0)
			preOrder(leftChild[cur]); // 왼쪽 자식
		if(rightChild[cur] != 0)
			preOrder(rightChild[cur]); // 오른쪽 자식
	}
	
	static void inOrder(int cur) {
		if(leftChild[cur] != 0)
			inOrder(leftChild[cur]); // 왼쪽 자식
		
		System.out.print((char)(cur + 'A')); // 루트
		
		if(rightChild[cur] != 0)
			inOrder(rightChild[cur]); // 오른쪽 자식
	}
	
	static void postOrder(int cur) {
		if(leftChild[cur] != 0)
			postOrder(leftChild[cur]); // 왼쪽 자식
		if(rightChild[cur] != 0)
			postOrder(rightChild[cur]); // 오른쪽 자식
		
		System.out.print((char)(cur + 'A')); // 루트
	}
}

