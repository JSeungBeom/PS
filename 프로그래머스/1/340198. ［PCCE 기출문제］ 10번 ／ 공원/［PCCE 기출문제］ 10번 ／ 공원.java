import java.util.*;


class Solution {
    private static boolean chk(int[] mats, String[][] park, int x, int y, int sz){
        
        for(int i = x; i < x + sz; i++){
            for(int j = y; j < y + sz; j++){
                if(!park[i][j].equals("-1")){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    public int solution(int[] mats, String[][] park) {
        int answer = 0;
        
        for(int i = 0; i < mats.length; i++){
            int sz = mats[i];
                        
            for(int j = 0; j <= park.length - sz; j++){
                for(int k = 0; k <= park[j].length - sz; k++){
                    if(chk(mats, park, j, k, sz))
                        answer = Math.max(answer, sz);
                }
            }
        }
        
        if(answer == 0)
            answer = -1;
        
        return answer;
    }
}