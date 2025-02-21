import java.util.*;

class Solution {
    static char[][] board;
    static int[] dx = {1, 0, -1, 0};
    static int[] dy = {0, 1, 0, -1};
    static int N, M;
    
    public int solution(String[] storage, String[] requests) {
        int answer = 0;
        
        N = storage.length;
        M = storage[0].length();
        
        board = new char[N + 2][M + 2];
        
        for(int i = 0; i < N + 2; i++){
            for(int j = 0; j < M + 2; j++){
                board[i][j] = 'x';
            }
        }
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                board[i + 1][j + 1] = storage[i].charAt(j);
            }
        }
        
        int len = requests.length;
        
        for(int i = 0; i < len; i++){
            if(requests[i].length() == 1){
                bfs(requests[i].charAt(0));
            }
            else{
                bfs2(requests[i].charAt(0));
            }
        }
        
        for(int i = 0; i < N + 2; i++){
            for(int j = 0; j < M + 2; j++){
                if(board[i][j] != 'x')
                    answer++;
                // System.out.print(board[i][j] + " ");
            }
            // System.out.println();
        }
        
        return answer;
    }
    
    static void bfs(char c){
        Queue<int[]> q = new ArrayDeque<>();
        
        q.offer(new int[] {0, 0});
        boolean[][] vis = new boolean[N + 2][M + 2];
        vis[0][0] = true;
        
        while(!q.isEmpty()){
            int[] cur = q.poll();
            
            int x = cur[0];
            int y = cur[1];
                                    
            for(int dir = 0; dir < 4; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                
                if(nx < 0 || nx >= N + 2 || ny < 0 || ny >= M + 2) continue;
                if(board[nx][ny] != c && board[nx][ny] != 'x') continue;
                if(vis[nx][ny]) continue;
                
                if(board[nx][ny] == c){
                    board[nx][ny] = 'x';
                    vis[nx][ny] = true;
                    continue;
                }
                vis[nx][ny] = true;
                q.offer(new int[] {nx, ny});
            }
        }
    }
    
    static void bfs2(char c){
        Queue<int[]> q = new ArrayDeque<>();
        boolean[][] vis = new boolean[N + 2][M + 2];

        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= M; j++){
                if(vis[i][j] || board[i][j] != c) continue;
                
                q.offer(new int[] {i, j});
                vis[i][j] = true;
                
                while(!q.isEmpty()){
                    int[] cur = q.poll();
                    
                    int x = cur[0];
                    int y = cur[1];
                    board[x][y] = 'x';

                    for(int dir = 0; dir < 4; dir++){
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];
                        
                        if(nx < 1 || nx > N || ny < 1 || ny > M) continue;
                        if(board[nx][ny] != c || vis[nx][ny]) continue;
                        
                        vis[nx][ny] = true;
                        q.offer(new int[] {nx, ny});
                    }
                }
            }
        }
        
    }
}