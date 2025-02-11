import java.util.*;

class Solution {
   public String[] solution(String[] record) {
		// Enter, Leave에 대한 문자열로 HashMap에 관리
		HashMap<String, String> msg = new HashMap<>();
		msg.put("Enter", "님이 들어왔습니다.");
		msg.put("Leave", "님이 나갔습니다.");
		
		// 유저 아이디별 닉네임 관리 HashMap
		HashMap<String, String> uid = new HashMap<>();
		
		for (String s : record) {
			String[] cmd = s.split(" ");
			
			if(cmd.length == 3) {
				uid.put(cmd[1], cmd[2]); // cmd[1] : 유저 아이디인데, 이 값이 중복되면 덮어쓴다
			}
		}
		
		// 정답 구성
		ArrayList<String> answer = new ArrayList<>();
		
		for (String s : record) {
			String[] cmd = s.split(" ");
			
			// Enter, Leave에 대해서만 처리 -> msg 이용
			if(msg.containsKey(cmd[0])) { // Change는 거른다
				answer.add(uid.get(cmd[1]) + msg.get(cmd[0]));
			}
		}
		
		return answer.toArray(new String[0]); // ArrayList => String[]
		
	}
}