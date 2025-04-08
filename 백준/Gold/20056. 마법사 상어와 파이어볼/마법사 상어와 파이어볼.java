import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
	
	static int N, M, K;
	
	static List<Fireball> list = new ArrayList<>(); // 모든 파이어볼의 정보를 저장하는 리스트
	static List<Fireball> tmp = new ArrayList<>();
	// 방향 따라 dx, dy 정의
	static int[] dx = { -1, -1, 0, 1, 1, 1, 0, -1 };
	static int[] dy = { 0, 1, 1, 1, 0, -1, -1, -1 };
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());
		
		for(int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			
			int r = Integer.parseInt(st.nextToken()); // 행
			int c = Integer.parseInt(st.nextToken()); // 열
			int m = Integer.parseInt(st.nextToken()); // 질량
			int s = Integer.parseInt(st.nextToken()); // 속도
			int d = Integer.parseInt(st.nextToken()); // 방향
		
			Fireball fireball = new Fireball(r, c, m, s, d);
			
			list.add(fireball);
		}
		
		// 이동 K번 명령
		for(int i = 0; i < K; i++) {			
			moveFireball(); // 파이어볼 이동
			unionFireball(); // 파이어볼이 2개 이상 있으면, 합쳐지고 4개로 나눠짐
			addFireball(); // 나눠진 파이어볼들을 다시 리스트에 담음
			
			
		}
		
		System.out.println(getMassSum());
	}
	
	// 파이어볼 이동
	static void moveFireball() {
		for(Fireball fireball : list) {
			// 속도만큼 방향으로 이동
			// N번 이동하면 제자리 -> 속도를 N으로 나눈 나머지 값만큼만 이동
			for(int i = 0; i < (fireball.s % N); i++) {
				int nx = fireball.r + dx[fireball.d];
				int ny = fireball.c + dy[fireball.d];
				
				// 격자의 1번 행은 N번과 연결, 1번 열은 N번 열과 연결
				// 이에 대한 처리
				if(nx < 1) {
					nx = N;
				}
				else if(nx > N) {
					nx = 1;
				}
				
				if(ny < 1) {
					ny = N;
				}
				else if(ny > N) {
					ny = 1;
				}
				
				// 실제 이동
				fireball.r = nx;
				fireball.c = ny;
			}
		}
	}
	
	// 파이어볼이 합쳐짐
	static void unionFireball() {
		// 행, 열 순으로 정렬
		Collections.sort(list, (f1, f2) -> f1.r == f2.r ? f1.c - f2.c : f1.r - f2.r);
		
		int r = -1;
		int c = -1;

		int mass = 0; // 합쳐진 파이어볼 질량의 합
		

		int speed = 0; // 합쳐진 파이어볼 속력의 합
		int count = 0; // 합쳐진 파이어볼 개수
		

		boolean isEven = true; // 모두 짝수 판단
		boolean isOdd = true; // 모두 홀수 판단
		
		int st = 0, en = 0; // 삭제 (합쳐질) 범위
		
		for(int i = list.size() - 1; i >= 0; i--) {
			if(list.get(i).r != r || list.get(i).c != c) {
				// 2개 이상의 파이어볼 나뉘어짐
				// 질량 : 질량의 합 / 5
				// 속력 : 속력의 합 / 개수
				// 모두 짝수 or 홀수 -> 방향 : 0, 2, 4, 6
				// 아니면 -> 방향 : 1, 3, 5, 7
				if(count >= 2) divideFireball(st, en, r, c, mass / 5, speed / count, isEven || isOdd);
					
				en = i; st = i;
				mass = list.get(i).m;
				speed = list.get(i).s;
				count = 1;
				r = list.get(i).r;
				c = list.get(i).c;
				
				isEven = true;
				isOdd = true;
				
				if(list.get(i).d % 2 == 0) isOdd = false;
				if(list.get(i).d % 2 == 1) isEven = false;
			}
			else {
				st--;
				mass += list.get(i).m;
				speed += list.get(i).s;
				count++;
				r = list.get(i).r;
				c = list.get(i).c;
				
				if(list.get(i).d % 2 == 0) isOdd = false;
				if(list.get(i).d % 2 == 1) isEven = false;
			}
		}
		
		if(count >= 2) divideFireball(st, en, r, c, mass / 5, speed / count, isEven || isOdd);
	}
	
	static void divideFireball(int st, int en, int r, int c, int m, int s, boolean isEvenOrOdd) {
		 // 모든 파이어볼 없앰
		for(int i = en; i >= st; i--) {
			list.remove(i);
		};

		if(m == 0) return;
		
		int dir = 0;
		
		if(isEvenOrOdd) dir = -2; // 0, 2, 4, 6
		else dir = -1; // 1, 3, 5, 7
		
		for(int i = 0; i < 4; i++) {	
			Fireball fireball = new Fireball(r, c, m, s, dir += 2);
			
			tmp.add(fireball);
		}

	}
	
	static void addFireball() {
		list.addAll(tmp);
		
		tmp.clear();
	}
	
	static int getMassSum() {
		int sum = 0;
		
		for(Fireball fireball : list) {
			sum += fireball.m;
		}
		
		return sum;
	}
	
	static class Fireball {
		
		int r; int c; int m; int s; int d;
		
		Fireball(int r, int c, int m, int s, int d){
			this.r = r;
			this.c = c;
			this.m = m;
			this.s = s;
			this.d = d;
		}

		@Override
		public String toString() {
			return "Fireball [r=" + r + ", c=" + c + ", m=" + m + ", s=" + s + ", d=" + d + "]";
		}
		
		
	}
}
