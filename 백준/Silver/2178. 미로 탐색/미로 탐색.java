import java.awt.*;
import java.util.*;
import java.io.*;

public class Main {

    static int N;
    static int M;
    static int[][] board;
    static int[][] dist;
    static int[] dx = new int[]{0, 1, 0, -1};
    static int[] dy = new int[]{1, 0, -1, 0};


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        board = new int[N][M];
        dist = new int[N][M];

        for(int i = 0; i < N; i++){
            Arrays.fill(dist[i], -1);
        }

        Queue<Point> q = new LinkedList<>();

        for(int i = 0; i < N; i++){
            String s = br.readLine();
            for(int j = 0; j < M; j++){
                board[i][j] = (int)(s.charAt(j) - '0');
            }
        }

        Point start = new Point(0, 0);
        q.add(start);
        dist[start.x][start.y] = 1;

        while(!q.isEmpty()){
            Point cur = q.poll();
            
            for(int dir = 0; dir < 4; dir++){
                int nx = cur.x + dx[dir];
                int ny = cur.y + dy[dir];

                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if(dist[nx][ny] >= 0 || board[nx][ny] == 0) continue;

                dist[nx][ny] = dist[cur.x][cur.y] + 1;
                q.add(new Point(nx, ny));
            }
        }

        System.out.print(dist[N - 1][M - 1]);

    }
}
