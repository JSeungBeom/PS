import java.util.*;

class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        String answer = "";
        
        Queue<String> queue1 = new ArrayDeque<>();
        Queue<String> queue2 = new ArrayDeque<>();
        
        for(String card : cards1){
            queue1.offer(card);
        }
        
        for(String card : cards2){
            queue2.offer(card);
        }
        
        int len = 0;
        
        for(int i = 0; i < goal.length; i++){

            if(!queue1.isEmpty() && queue1.peek().equals(goal[i])){
                queue1.poll(); len++;
            }
            else if(!queue2.isEmpty() && queue2.peek().equals(goal[i])){
                queue2.poll(); len++;
            }
        }
        
        System.out.println(len);
        
        if(len == goal.length)
            answer = "Yes";
        else
            answer = "No";
        
        return answer;
    }
}