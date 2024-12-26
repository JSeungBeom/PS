import java.util.*;
import java.lang.*;

class Pair {
    int x;
    int y;
    
    public Pair(int x, int y){
        this.x = x;
        this.y = y;
    }
}

class Solution {
    public int solution(int[][] maps) {
        
        int[] dx = new int[]{0, -1, 0, 1};
        int[] dy = new int[]{1, 0, -1, 0};
        int answer = 0;
        
        Queue<Pair> q = new LinkedList<>();
        
        int n = maps.length;
        int m = maps[0].length;

        Integer[][] dist = new Integer[n][m];

        for(int i = 0; i < n; i++){
            Arrays.fill(dist[i], -1);
        }
        
        q.add(new Pair(0, 0));
        dist[0][0] = 1;
        
        while(!q.isEmpty()){
            Pair cur = q.poll();
            
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];
                
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(dist[nx][ny] >= 0 || maps[nx][ny] == 0) continue;
                
                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                q.add(new Pair(nx, ny));
            }
        }
        
        return dist[n - 1][m - 1];
    }
}