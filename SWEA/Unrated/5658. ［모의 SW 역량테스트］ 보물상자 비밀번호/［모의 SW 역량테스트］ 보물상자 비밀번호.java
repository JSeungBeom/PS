/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// double b;
// char g;
// String var;
// long AB;
// a = sc.nextInt();                           // int 변수 1개 입력받는 예제
// b = sc.nextDouble();                        // double 변수 1개 입력받는 예제
// g = sc.nextByte();                          // char 변수 1개 입력받는 예제
// var = sc.next();                            // 문자열 1개 입력받는 예제
// AB = sc.nextLong();                         // long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// double b = 1.0;               
// char g = 'b';
// String var = "ABCDEFG";
// long AB = 12345678901234567L;
//System.out.println(a);                       // int 변수 1개 출력하는 예제
//System.out.println(b); 		       						 // double 변수 1개 출력하는 예제
//System.out.println(g);		       						 // char 변수 1개 출력하는 예제
//System.out.println(var);		       				   // 문자열 1개 출력하는 예제
//System.out.println(AB);		       				     // long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

/*
   사용하는 클래스명이 Solution 이어야 하므로, 가급적 Solution.java 를 사용할 것을 권장합니다.
   이러한 상황에서도 동일하게 java Solution 명령으로 프로그램을 수행해볼 수 있습니다.
 */
class Solution
{
    
    public static int ctoi(char c) {
        return c - 'A' + 10;
    }
    
	 public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());

        for (int test_case = 1; test_case <= T; test_case++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int K = Integer.parseInt(st.nextToken());

            Deque<Integer> dq = new ArrayDeque<>();
            HashSet<Long> set = new HashSet<>();
            ArrayList<Long> list = new ArrayList<>();

            String s = br.readLine();

            for (int i = 0; i < N; i++) {
                char c = s.charAt(i);
                if (Character.isLetter(c)) {
                    dq.addLast(ctoi(c));
                } else {
                    dq.addLast(c - '0');
                }
            }

            int sz = N / 4;

            for (int rot = 0; rot < sz; rot++) {
                List<Integer> temp = new ArrayList<>(dq);

                for (int i = sz; i <= N; i += sz) {
                    long num = 0;
                    long mul = 1;

                    for (int j = i - 1; j >= i - sz; j--) {
                        num += temp.get(j) * mul;
                        mul *= 16;
                    }

                    set.add(num);
                }

                // 회전
                dq.addFirst(dq.pollLast());
            }

            list.addAll(set);
            Collections.sort(list);

            System.out.println("#" + test_case + " " + list.get(list.size() - K));
        }
    }
}