import java.util.*;

class Solution {
    public int solution(int[][] board, int[] moves) {
        int answer = 0;
        
        Deque<Integer> stack = new ArrayDeque<>();
        
        for(int move : moves){
            int x = move - 1;
            int y = 0;
            
            while(y < board.length && board[y][x] == 0) y++;
            
            if(y >= board.length) continue;
            
            if(stack.isEmpty()){
                stack.push(board[y][x]);
                board[y][x] = 0;
            } else {
                if(stack.peek() == board[y][x]){
                    stack.pop(); answer += 2;
                    board[y][x] = 0;
                }
                else {
                    stack.push(board[y][x]);
                    board[y][x] = 0;
                }     
            }
            
           
        }
        
        return answer;
    }
}