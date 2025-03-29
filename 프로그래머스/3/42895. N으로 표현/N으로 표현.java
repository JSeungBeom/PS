import java.util.*;

class Solution {
    static List<Set<Integer>> dp = new ArrayList<>();
    
    public int solution(int N, int number) {
        for(int i = 0; i <= 8; i++){
            dp.add(new HashSet<Integer>());
        }
        
        int num = 0;
        
        for(int i = 1; i <= 8; i++){
            num = num * 10 + N;
            dp.get(i).add(num);
            
            for(int j = 1; i + j <= 8 && j <= i; j++){                        
                for(int a : dp.get(i)){
                    for(int b : dp.get(j)){
                        dp.get(i + j).add(a + b);
                        
                        dp.get(i + j).add(a - b);
                        dp.get(i + j).add(b - a);
                        
                        dp.get(i + j).add(a * b);
                        
                        if(b != 0) dp.get(i + j).add(a / b);
                        if(a != 0) dp.get(i + j).add(b / a);
                    }
                }
            }
            
            if(dp.get(i).contains(number))
                return i;
        }
        
        
        return -1;
    }
}