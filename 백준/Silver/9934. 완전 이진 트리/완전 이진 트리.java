import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

	static int K;
	static int[] tree;
	static List<List<Integer>> list = new ArrayList<>();
	static int size;
	static int root;
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		K = Integer.parseInt(br.readLine());
		
		for(int i = 0; i <= K; i++) {
			list.add(new ArrayList<>());
		}
		size = (1 << K) - 1;
		
		tree = new int[size];
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int i = 0; i < size; i++) {
			tree[i] = Integer.parseInt(st.nextToken());
		}
		
		if(K == 1) {
			System.out.println(tree[0]);
			return;
		}
		
		root = size / 2;
		int diff = 1 << (K - 1);

		find_tree(root, diff, 0);
		
		print_tree();
	}
	
	static void find_tree(int cur, int diff, int depth) {
		if(diff == 0)
			return;
		
		list.get(depth).add(cur);
		diff >>= 1;
		
		find_tree(cur - diff, diff, depth + 1);

		find_tree(cur + diff, diff, depth + 1);
	}
	
	static void print_tree() {
		for(int i = 0; i < K; i++) {
			for(int node : list.get(i)) {
				System.out.print(tree[node] + " ");
			}
			System.out.println();
		}
	}
	
}
