import java.util.*;

class Solution {
    static PriorityQueue<Job> pq;
    
    public int solution(int[][] jobs) {
        int answer = 0;
        int size = jobs.length;
        int time = 0, idx = 0;
        
        // 요청 시간 순으로 정렬 (jobs[i][0] 기준)
        Arrays.sort(jobs, (a, b) -> a[0] - b[0]);
        
        pq = new PriorityQueue<>((j1, j2) -> j1.exec - j2.exec);
        
        int count = 0;
        
        while (count < size) {
            // 현재 시간 이하에서 요청된 작업들을 우선순위 큐에 추가
            while (idx < size && jobs[idx][0] <= time) {
                pq.add(new Job(jobs[idx][1], jobs[idx][0]));
                idx++;
            }

            if (!pq.isEmpty()) {
                Job curJob = pq.poll();
                time += curJob.exec;
                answer += (time - curJob.req);
                count++;
            } else {
                // 실행할 작업이 없으면 다음 요청 시간으로 이동
                time = jobs[idx][0];
            }
        }

        return answer / size;
    }
    
    static class Job {
        int exec;
        int req;
        
        Job(int exec, int req){
            this.exec = exec;
            this.req = req;
        }
    }
}
