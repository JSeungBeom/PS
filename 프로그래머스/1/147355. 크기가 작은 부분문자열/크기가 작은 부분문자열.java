class Solution {
    public int solution(String t, String p) {
        int answer = 0;
        
        int size = t.length();
        int len = p.length();
        
        long ip = Long.parseLong(p);
        
        for(int i = 0; i <= size - len; i++){
            String tmp = "";
            for(int j = i; j < i + len; j++){
                tmp += t.charAt(j);
            }
            
            long tp = Long.parseLong(tmp);
                                    
            if(tp <= ip){
                answer++;
            }
        }
        
        return answer;
    }
}