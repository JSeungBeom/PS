import java.util.*;

class Solution {
    
    static PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
    
    public long solution(int n, int[] works) {
        long answer = 0;
        
        for(int i = 0; i < works.length; i++){
            pq.add(works[i]);
        }
        
        for(int i = 0; i < n; i++) {
            int cur = pq.poll();
            
            cur--;
            
            if(cur != 0)
                pq.add(cur);
            if(pq.isEmpty()) break;        
        }
        
        for(int cur : pq) {
            answer += (cur * cur);
        }
        
        return answer;
    }
}