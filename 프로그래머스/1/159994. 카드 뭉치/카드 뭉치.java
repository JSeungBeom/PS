import java.util.*;

class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
		Queue<String> cardsDeque1 = new ArrayDeque<>(Arrays.asList(cards1));
		Queue<String> cardsDeque2 = new ArrayDeque<>(Arrays.asList(cards2));
		Queue<String> goalDeque = new ArrayDeque<>(Arrays.asList(goal));
		
		while(!goalDeque.isEmpty()) {
			if(!cardsDeque1.isEmpty() && cardsDeque1.peek().equals(goalDeque.peek())) {
				cardsDeque1.poll();
				goalDeque.poll();
			} else if(!cardsDeque2.isEmpty() && cardsDeque2.peek().equals(goalDeque.peek())) {
				cardsDeque2.poll();
				goalDeque.poll();
			}
			else {
				break;
			}
		}
		
		if(goalDeque.isEmpty()) return "Yes";
		else return "No";
		
	}
}