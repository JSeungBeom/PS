import java.util.*;

class Solution {
    static PriorityQueue<Integer> pq = new PriorityQueue<>();
    
    public int solution(int[] scoville, int K) {
        int answer = 0;
        int size = scoville.length;
        
        for(int i = 0; i < size; i++){
            pq.add(scoville[i]);
        }
        
        while(!pq.isEmpty()){
            int a = pq.poll();
            if(a >= K){
                return answer;
            }
            if(pq.isEmpty()){
                break;
            }
            int b = pq.poll();
            
            int mixed = a + (b * 2);
            
            answer++;
            
            pq.add(mixed);
        }
        
        return -1;
    }
}