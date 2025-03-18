import java.util.*;

class Solution {
    static int n;
    static boolean[] vis;
    static List<String> ans = new ArrayList<>();
    
    public String[] solution(String[][] tickets) {
        n = tickets.length;
        vis = new boolean[n + 1];
        String[] answer = new String[n + 1];
        
        back_tracking(0, "ICN", "ICN", tickets);
        
        // for(int i = 0; i < n; i++){
        //     answer[i] = list.get(i);
        // }
        
        Collections.sort(ans);
        StringTokenizer st = new StringTokenizer(ans.get(0), ",");
        
        for(int i = 0; i <= n; i++){
            answer[i] = st.nextToken();
        }
        
        return answer;
    }
    
    static void back_tracking(int k, String start, String path, String[][] tickets){
        if(k == n){
            ans.add(path);
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(vis[i] || !start.equals(tickets[i][0])) continue; 
            vis[i] = true;
            
            back_tracking(k + 1, tickets[i][1], path + "," + tickets[i][1], tickets);
            
            vis[i] = false;
        }
    }
}