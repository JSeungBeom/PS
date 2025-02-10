import java.util.*;

class Solution
{
    public int solution(String s)
    {
        Deque<Character> stack = new ArrayDeque<>();
        
        char[] c = s.toCharArray();
        
        for(int i = 0; i < c.length; i++) {
            if(!stack.isEmpty() && stack.peek() == c[i]){
                stack.pop();
            } else {
                stack.push(c[i]);
            }
        }
    
        if(stack.isEmpty())
            return 1;
        else
            return 0;
    }
}