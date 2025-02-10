import java.util.*;

class Solution {
	boolean solution(String s) {
		char[] input = s.toCharArray();
		int len = input.length;
		int xCnt = 0; // ()가 한쌍으로 일치하면 'X'로 표시, 그 건수
		for (int i = 0, oi = 0; i < len; i++) {
			if(input[i] == ')') { // 닫는 괄호
				if( input[oi] != '(' ) return false;
				
				// 두 괄호가 일치
				input[i] = 'X';
				input[oi] = 'X';
				xCnt += 2; // 일치해서 처리된 항목 수 2 증가 
				
				while(oi > 0 && input[oi] == 'X') oi--; // 현재 oi 자리가 'X'가 되면서 이전 자리 중 여는 괄호가 있는 마지막 위치
			} else { // 여는 괄호
				oi = i;
			}
		}
		
		return xCnt == len;
	}
}