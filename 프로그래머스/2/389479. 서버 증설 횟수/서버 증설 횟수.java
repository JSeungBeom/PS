import java.util.*;

class Solution {
        
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        
        int size = players.length;
        List<int[]> servers = new ArrayList<>();
        
        for(int i = 0; i < size; i++){
            int cur = 0;
            if(!servers.isEmpty()){
                for(int j = servers.size() - 1; j >= 0; j--){
                    servers.get(j)[1] -= 1;
                    
                    if(servers.get(j)[1] == 0)
                        servers.remove(j);
                }
                
                
                for(int[] server : servers){
                    cur += server[0];
                }
            }
            
            if(((cur + 1) * m) <= players[i]){
                servers.add(new int[] { (players[i] - cur * m) / m, k});
                answer += (players[i] - cur * m) / m;
                
            }
            
        }
        
        
        return answer;
    }
}