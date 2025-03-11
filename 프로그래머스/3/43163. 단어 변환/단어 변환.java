import java.util.*;

class Solution {
    
    static Queue<String> q = new ArrayDeque<>();
    static HashMap<String, Integer> map = new HashMap<>();
    
    public int solution(String begin, String target, String[] words) {
        int answer = 0;
        
        int size = words.length;
        int len = begin.length();
        
        q.offer(begin);
        map.put(begin, 0);
        
        while(!q.isEmpty()){
            String cur = q.poll();
            
            for(int i = 0; i < size; i++){
                int cnt = 0;
            
                for(int j = 0; j < len; j++){
                    if(cur.charAt(j) != words[i].charAt(j)){
                        cnt++;            
                    }
                }
                if(cnt != 1) continue; 
                if(map.containsKey(words[i])) continue;
                
                map.put(words[i], map.get(cur) + 1);
                
                q.offer(words[i]);
            }
        }
        
        if(map.containsKey(target))
            answer = map.get(target);
        
        return answer;
    }
}