import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
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

        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < M; i++){
            String question = br.readLine();
            if(Character.isDigit(question.charAt(0))) { // 문자로 시작하는지 확인
                sb.append(itos.get(Integer.parseInt(question))).append("\n");
            } else {
                sb.append(stoi.get(question)).append("\n");
            }
        }

        bw.write(sb.toString());
        bw.flush();
    }
}
