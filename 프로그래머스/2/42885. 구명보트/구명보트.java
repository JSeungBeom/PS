import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
    	
    	// 무게별로 정렬
    	Arrays.sort(people); // 가벼운 ~ 무거운 순
    	int count = 0; // 총 사용된 구명보트 순
    	int i = 0; // 가장 가벼운 왼쪽 끝에서 시작 인덱스
    	int j = people.length - 1; // 가장 무거운 오른쪽 끝에서 시작 인덱스
    	
    	// 모두 다 태울 때까지 반복
    	while (i <= j) {
    		
    		// 현 시점, 가장 무거운 사람과 가장 가벼운 사람 고려
    		if(people[i] + people[j] <= limit) {
    			i++; // 가벼운 사람도 함께 태움
    		}
    		
    		// 무조건 무거운 사람 태운다
    		j--;
    		count++;
    	}
    	
        return count;
    }
}