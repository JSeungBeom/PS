import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        
        HashMap<String, Integer> players = new HashMap<>();
        
        for(int i = 0; i < participant.length; i++){
            if(players.containsKey(participant[i])){
                players.put(participant[i], players.get(participant[i]) + 1);
            }
            else{
                players.put(participant[i], 1);
            }
        }
        
        for(int i = 0; i < completion.length; i++){
            players.put(completion[i], players.get(completion[i]) - 1);
            
            if(players.get(completion[i]) == 0)
                players.remove(completion[i]);
        }
        
        Set<String> keys = players.keySet();
        
        for(String key : keys){
            answer += key;
        }
        
        return answer;
    }
}