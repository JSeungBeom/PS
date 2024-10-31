import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        HashMap<String, Integer> stoi = new HashMap<>();
        HashMap<Integer, String> itos = new HashMap<>();

        for(int i = 1; i <= N; i++){
            String name = br.readLine();

            stoi.put(name, i);
            itos.put(i, name);
        }

        for(int i = 0; i < M; i++){
            String question = br.readLine();
            if(0 <= question.charAt(0) - '0' && 9 >= question.charAt(0) - '0')
                System.out.println(itos.get(Integer.parseInt(question)));
            else
                System.out.println(stoi.get(question));

        }
    }
}
