class Solution {
    public int solution(int[] schedules, int[][] timelogs, int startday) {
        int answer = 0;
        
        for(int i = 0; i < schedules.length; i++){
            int hour = schedules[i] / 100;
            int minute = schedules[i] % 100;
            
            if(minute + 10 >= 60)
                hour += 1;
            
            minute = (minute + 10) % 60;
            
            schedules[i] = hour * 100 + minute;
            
        }
        
        
        for(int i = 0; i < timelogs.length; i++){
            int st = startday;
            boolean receivable = true;

            for(int j = 0; j < 7; j++){
                if(timelogs[i][j] > schedules[i] && st <= 5){
                    receivable = false;
                }
                st++;
                if(st == 8)
                    st = 1;
             
            }
            
            if(receivable) 
                answer++;
        }
        return answer;
    }
}