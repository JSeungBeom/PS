import java.util.*;

class Solution {
    public String[] solution(String[] record) {
        HashMap<String, String> hashMap = new HashMap<>();
        
        int length = 0;
        
        for(int i = 0; i < record.length; i++){
            StringTokenizer st = new StringTokenizer(record[i]);
            
            String com = st.nextToken();
            String uid = st.nextToken();
            if(com.equals("Enter") || com.equals("Change")){
                String nickname = st.nextToken();
                hashMap.put(uid, nickname);    
            } 
            
            if(com.equals("Enter") || com.equals("Leave")){
                length++;
            }
        }
        
        String[] answer = new String[length];
        int idx = 0;
        
        for(int i = 0; i < record.length; i++){
            StringTokenizer st = new StringTokenizer(record[i]);
            
            String com = st.nextToken();
            String uid = st.nextToken();
            
            if(com.equals("Enter")){
                String nickname = hashMap.get(uid);
                
                answer[idx++] = nickname + "님이 들어왔습니다.";
            } else if(com.equals("Leave")){
                String nickname = hashMap.get(uid);
                
                answer[idx++] = nickname + "님이 나갔습니다.";
            }
        }
        
        return answer;
    }
}