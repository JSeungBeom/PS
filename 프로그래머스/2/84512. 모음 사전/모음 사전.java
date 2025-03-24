class Solution {
    static char[] alpha = {'A', 'E', 'I', 'O', 'U'};
    
    public int solution(String word) {
        int answer = 0;
        
        StringBuilder sb = new StringBuilder();
        
        for(int a = 0; a < 5; a++){
            sb.append(alpha[a]);
            answer++;
            if(word.equals(sb.toString())) return answer;
            for(int b = 0; b < 5; b++){
                sb.append(alpha[b]);
                answer++;
                if(word.equals(sb.toString())) return answer;
            
                for(int c = 0; c < 5; c++){
                    sb.append(alpha[c]);
                    answer++;
                    if(word.equals(sb.toString())) return answer;
                    
                    for(int d = 0; d < 5; d++){
                        sb.append(alpha[d]);
                        answer++;
                        if(word.equals(sb.toString())) return answer;
                        

                        for(int e = 0; e < 5; e++){
                            sb.append(alpha[e]);
                            answer++;

                            if(word.equals(sb.toString())) return answer;
                            sb.deleteCharAt(sb.length() - 1);
                            
                        }
                        sb.deleteCharAt(sb.length() - 1);
                    }
                    sb.deleteCharAt(sb.length() - 1);
                }
                sb.deleteCharAt(sb.length() - 1);
            }
            sb.deleteCharAt(sb.length() - 1);
        }
        
        return answer;
    }
}