
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
public class Main {
    // 백트래킹 - 이전에 놓은 파이프라인이 다음에 놓을 파이프라인에 영향을 미친다. ( 겹치면 X )
    // 그리디 - 최대한 많은 파이프라인....<= 왼쪽에서 오른쪽으로 이어지는 탐색 중 우선 순위 ( 우상 -> 우 -> 우하 )
    // 우선 순위대로 방문했을 때 성공하면 다음 우선순위의 탐색을 (delta) 이어가면 안되고, 바로 종료
    // 항상 현재 좌표에서 유리한 방향 1 가지만 성공하면 탐색 종료
    // visit - 특정 좌표를 탐색의 과정에서 방문하게 되면 무조건 'x' 표시 ( 현재 탐색이 성공, 실패 상관없이 )
    
    static int R, C, ans;
    static char[][] map;
    
    // delta 순서
    static int[] dx = { -1, 0, 1 }; // x 는 항상 +1, y 는 우상, 우, 우하
    
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        R = Integer.parseInt(st.nextToken());
        C = Integer.parseInt(st.nextToken());
        
        map = new char[R][]; // String toCharArray()
        
        for (int i = 0; i < R; i++) {
            map[i] = br.readLine().toCharArray();
        }
        
        // 각 행별로 밑으로 내려가면서 탐색 진행
        for (int i = 0; i < R; i++) {
            if( dfs(i, 0) ) ans++; //  i 번째 row 에서 왼쪽부터 오른쪽끝까지 모두 연결 성공한 경우
        }
        
        System.out.println(ans);
    }
    static boolean dfs(int x, int y) {
        
        int ny = y + 1; // 옆으로 한 칸 이동
        
        if( ny == C - 1 ) return true; // 빵집까지 도달
        
        // 우선순위를 가진 delta 다음 방문 진행
        // 다음 재귀호출의 결과가  true 이면 성공이고 이 때 다음 delta 방문 하면 X
        for (int d = 0; d < 3; d++) {
            int nx = x + dx[d];
            
            if( nx < 0 || nx >= R || map[nx][ny] == 'x' ) continue;
            map[nx][ny] = 'x'; // 성공해도, 실패해도 다시 방문 X
            if( dfs(nx, ny) ) return true; // 현재 좌표에서 성공
        }
        
        // 현재 좌표에서 성공 X
        return false;
    }
}
