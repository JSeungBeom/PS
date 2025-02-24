class Solution {
    
    static int[][] board;
    static int size;
    
    public int solution(int n, int w, int num) {
        int answer = 0;
        
        if(n % w == 0)
            size = n / w;
        else
            size = n / w + 1;
        
        board = new int[size][w];
        int st = 1;
        boolean rev = false;
        
        for(int i = size - 1; i >= 0; i--){
            if(rev){
                for(int j = w - 1; j >= 0; j--){
                    board[i][j] = st++;  
                    if(st > n) break;
                }
                
                rev = false;
            } else {
                for(int j = 0; j < w; j++) {
                    board[i][j] = st++;
                    if(st > n) break;
                }
                
                rev = true;
            }    
        }
        

        
        for(int i = 0; i < size; i++){
            for(int j = 0; j < w; j++){
                if(board[i][j] == num){
                    for(int k = i; k >= 0; k--){
                        if(board[k][j] != 0)
                            answer++;
                    }
                    
                    return answer;
                }
            }
        }
        
        return answer;
    }
}