import java.util.*;

class Solution {
    static Map<String, Integer> map = new HashMap<>();
    
    public int solution(String[] want, int[] number, String[] discount) {
        int answer = 0;

        int len = discount.length;
        
        for(int i = 0; i <= len - 10; i++) {
            for(int j = 0; j < want.length; j++) 
                map.put(want[j], number[j]);
        
            boolean flag = true;
            for(int j = i; j < i + 10; j++) {
                if(map.containsKey(discount[j]))
                    map.put(discount[j], map.get(discount[j]) - 1);
            }
            
            for(String key : map.keySet()) {
                if(map.get(key) > 0) {
                    flag = false; break;
                }
            }
            
            if(flag) answer++;
            
            
        }
        
        
        return answer;
    }
}