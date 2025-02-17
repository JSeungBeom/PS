import java.io.*;

public class Main {
    static int[][] board = new int[9][9];
    static boolean[][] rowUsed = new boolean[9][10];
    static boolean[][] colUsed = new boolean[9][10];
    static boolean[][][] boxUsed = new boolean[3][3][10];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        for (int i = 0; i < 9; i++) {
            String s = br.readLine();
            for (int j = 0; j < 9; j++) {
                board[i][j] = s.charAt(j) - '0';
                if (board[i][j] != 0) {
                    int num = board[i][j];
                    rowUsed[i][num] = true;
                    colUsed[j][num] = true;
                    boxUsed[i / 3][j / 3][num] = true;
                }
            }
        }

        solve(0, 0);
    }

    static boolean solve(int x, int y) {
        if (y == 9) {  
            return solve(x + 1, 0);
        }
        if (x == 9) {  
            printBoard();
            return true;
        }

        if (board[x][y] != 0) { 
            return solve(x, y + 1);
        }

        for (int num = 1; num <= 9; num++) {
            if (!rowUsed[x][num] && !colUsed[y][num] && !boxUsed[x / 3][y / 3][num]) {
                board[x][y] = num;
                rowUsed[x][num] = colUsed[y][num] = boxUsed[x / 3][y / 3][num] = true;

                if (solve(x, y + 1)) return true; 

                board[x][y] = 0;
                rowUsed[x][num] = colUsed[y][num] = boxUsed[x / 3][y / 3][num] = false;
            }
        }
        return false; 
    }

    static void printBoard() {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                sb.append(board[i][j]);
            }
            sb.append("\n");
        }
        System.out.print(sb);
    }
}
