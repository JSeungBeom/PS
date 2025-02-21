class Solution {
    
    static boolean[] vis;
    static int[] arr;
    static int N;
    static int answer;
    public int solution(int n, int[][] q, int[] ans) {
        
        N = n;
        
        vis = new boolean[n];
        arr = new int[n];
        
        comb(0, 0, q, ans);
        
        return answer;
    }
    
    static void comb(int k, int st, int[][] q, int[] ans){
        if(k == 5){
            for(int i = 0; i < q.length; i++){
                int cnt = 0;
                for(int a = 0; a < 5; a++){
                    for(int b = 0; b < 5; b++){
                        if(q[i][a] == arr[b]){
                            cnt++;
                        }
                    }
                }
                
                if(cnt != ans[i]) return;
            }
            
            answer++;
            return;
        }
        
        for(int i = st; i < N; i++) {
            if(vis[i]) continue;
            
            vis[i] = true;
            arr[k] = i + 1;
            comb(k + 1, i, q, ans);
            vis[i] = false;
        }
    }
    
}