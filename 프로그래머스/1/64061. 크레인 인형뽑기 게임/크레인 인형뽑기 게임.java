import java.util.*;

class Solution {
public int solution(int[][] board, int[] moves) {
    	Stack<Integer>[] lanes = new Stack[board.length];
    	for (int i = 0; i < lanes.length; i++) {
			lanes[i] = new Stack<>();
		}
    	
    	// 그리드 형태의 각 열별 Stack에 입력을 담는다.
    	
    	for (int i = board.length - 1; i >= 0; i--) {
			for(int j = 0; j < board[i].length; j++) {
				if(board[i][j] > 0) {
					lanes[j].push(board[i][j]);
				}
			}
		}
    	
    	// 스택의 내용 확인
    	for (int i = 0; i < lanes.length; i++) {
			System.out.println(Arrays.toString(lanes[i].toArray())); // Array로 변경하여 출력
		}
    	
    	Stack<Integer> bucket = new Stack<>();
    	int answer = 0;
    	
    	for(int move : moves) { // 1 based index
     		if(lanes[move - 1].isEmpty()) continue;
     		
     		int doll = lanes[move - 1].pop();
     		
     		if(!bucket.isEmpty() && doll == bucket.peek()) { // 같은 읺여
     			bucket.pop();
     			answer += 2;
     		} else {
     			bucket.push(doll);
     		}
    	}
    
    	 return answer;
    }
}