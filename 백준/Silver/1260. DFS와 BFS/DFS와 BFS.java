import java.util.*;
import java.io.*;

public class Main {

    static int N, M, V;

    static LinkedList<Integer>[] adjList;
    static boolean[] dfs_vis;

    static void BFS(int st){
        Queue<Integer> q = new LinkedList<>();
        boolean[] vis = new boolean[N + 1];

        q.add(st);
        vis[st] = true;

        while(!q.isEmpty()){
            int cur = q.remove();

            System.out.print(cur + " ");
            for(int nxt : adjList[cur]){
                if(!vis[nxt]){
                    vis[nxt] = true;
                    q.add(nxt);
                }
            }
        }
    }

    static void DFS(int cur){
        if(dfs_vis[cur]) return;

        dfs_vis[cur] = true;
        System.out.print(cur + " ");
        for(int nxt : adjList[cur]){
            DFS(nxt);
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        V = Integer.parseInt(st.nextToken());

        adjList = new LinkedList[N + 1];
        dfs_vis = new boolean[N + 1];

        for(int i = 1; i <= N; i++){
            adjList[i] = new LinkedList<>();
        }

        for(int i = 0; i < M; i++){
            st = new StringTokenizer(br.readLine());
            int u = Integer.parseInt(st.nextToken());
            int v = Integer.parseInt(st.nextToken());

            adjList[u].add(v);
            adjList[v].add(u);
        }

        for(int i = 1; i <= N; i++){
            Collections.sort(adjList[i]);
        }

        DFS(V);
        System.out.println();
        BFS(V);
    }

}
