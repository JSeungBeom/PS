import java.util.*;

public class Solution {
    public int[] solution(int []arr) {        
        Stack<Integer> s = new Stack<>();
        
        for(int i = 0; i < arr.length; i++){
            if(!s.isEmpty()){
                if(s.peek() == arr[i])
                    continue;
            }
            
            s.push(arr[i]);
        }
        
        int[] answer = new int[s.size()];
        
        for(int i = s.size() - 1; i >= 0; i--){
            answer[i] = s.pop();
        }

        return answer;
    }
}