import java.util.*;
import java.lang.*;
import java.awt.*;

class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        
        Queue<Point> q = new LinkedList<>();
        
        int[] cpy = new int[priorities.length];
        
        for(int i = 0; i < priorities.length; i++)
            cpy[i] = priorities[i];
        
        Arrays.sort(cpy);
        
        for(int i = 0; i < priorities.length; i++){
            q.add(new Point(i, priorities[i]));
        }
            
        int st = cpy.length - 1;
        
        while(!q.isEmpty()){
            Point cur = new Point();
            cur = q.poll();
                    
            if(cpy[st] == cur.y){
                st--; answer++;   
                            
                if(cur.x == location){
                    break;
                }
            }
            else{
                q.add(cur);
            }

            
        }
        
        return answer;
    }
}