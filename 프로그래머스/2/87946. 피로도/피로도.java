import java.util.*;

class Solution {
    static int n;
    static boolean[] vis;
    static int[] arr;
    static int mx;
    
    public int solution(int k, int[][] dungeons) {
        n = dungeons.length;
        vis = new boolean[n];
        arr = new int[n];

        backtracking(0, k, dungeons);
        
        return mx;
    }
    
    static void backtracking(int k, int cur, int[][] dungeons) {
        if(mx == n)
            return;
        if(n == k){
            int cnt = 0;
            int now = cur;
            for(int i = 0; i < n; i++){
                
                if(dungeons[arr[i]][0] <= now) {
                    now -= dungeons[arr[i]][1]; cnt++;
                }
            }
            
            System.out.println();
            
            mx = Math.max(cnt, mx);
            
            
            return;
        }
        
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            
            arr[k] = i;
            vis[i] = true;
            
            backtracking(k + 1, cur, dungeons);
            
            vis[i] = false;
        }
    }
}