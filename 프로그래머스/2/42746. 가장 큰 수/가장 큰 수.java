import java.util.*;

class Solution {
    public String solution(int[] numbers) {        
        String[] nums = new String[numbers.length];
        
        StringBuilder sb = new StringBuilder();
        
        for(int i = 0; i < numbers.length; i++){
            nums[i] = String.valueOf(numbers[i]);
        }
        
        Arrays.sort(nums, (o1, o2) -> {
            String s1 = o1 + o2;
            String s2 = o2 + o1;
            
            return s2.compareTo(s1);
        });
        
        for(String num : nums){
            sb.append(num);
        }
        
        String answer = sb.toString();
        
        if(answer.charAt(0) == '0') answer = "0";
        
        return answer;
    }
}