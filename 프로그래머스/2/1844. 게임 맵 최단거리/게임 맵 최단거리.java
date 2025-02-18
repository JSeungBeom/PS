import java.util.*;

class Solution {
    
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static Queue<int[]> q = new ArrayDeque<>();
    static int[][] dist;
    static int n, m;
    
    public int solution(int[][] maps) {    
        n = maps.length;
        m = maps[0].length;
        
        dist = new int[n][m];
        
        for(int i = 0; i < n; i++)
            Arrays.fill(dist[i], -1);
        
        q.offer(new int[] {0, 0});
        dist[0][0] = 1;
        
        while(!q.isEmpty()){
            int[] cur = q.poll();
            
            int x = cur[0];
            int y = cur[1];
            
            for(int dir = 0; dir < 4; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(maps[nx][ny] == 0 || dist[nx][ny] >= 0) continue;
                
                dist[nx][ny] = dist[x][y] + 1;
                q.offer(new int[] {nx, ny});
            }
        }
        
        return dist[n - 1][m - 1];
    }
}