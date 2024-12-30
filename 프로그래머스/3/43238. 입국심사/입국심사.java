import java.util.*;

class Solution {
    public boolean binary_search(int n, int[] times, long mid){
        long cnt = 0L;
        
        for(int time : times){
            cnt += (mid / time);
        }
        
        return cnt >= n;
    }
    
    public long solution(int n, int[] times) {
        long answer = 0;
        
        long st = 0;
        long en = 100000 * 1000000000L;
                
        while(st < en){
            long mid = (st + en) / 2;
            
            if(binary_search(n, times, mid))
                en = mid;
            else
                st = mid + 1;
        }
                
        return st;
    }
}