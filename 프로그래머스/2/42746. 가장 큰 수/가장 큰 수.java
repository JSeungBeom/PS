import java.util.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        
        String[] nums = new String[numbers.length];
        
        for(int i = 0; i < nums.length; i++){
            nums[i] = Integer.toString(numbers[i]);
        }
        
        Arrays.sort(nums, new Comparator<String>() {
            @Override
            public int compare(String a, String b){
                String o1 = a + b;
                String o2 = b + a;
                
                return o2.compareTo(o1);
            }
        });
        
        for(int i = 0; i < nums.length; i++){
            answer += nums[i];
        }
        
        if (nums[0].equals("0")) {
            return "0";
        }
        
        return answer;
    }
}