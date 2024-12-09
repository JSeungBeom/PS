#include <string>
#include <vector>
#include <iostream>

using namespace std;

int n = 3;
    
int chk(vector<string> board){
    bool check[2] = {0};
    
    for(int i = 0; i < n; i++){
        int cntX = 0;
        int cntO = 0;
        
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'X')
                cntX++;
            if(board[i][j] == 'O')
                cntO++;
        }

        if(cntO == 3) check[0] = 1;
        if(cntX == 3) check[1] = 1;
    }
    
    for(int j = 0; j < n; j++){
        int cntX = 0;
        int cntO = 0;
        
        for(int i = 0; i < n; i++){
            if(board[i][j] == 'X')
                cntX++;
            if(board[i][j] == 'O')
                cntO++;
        }
        
        if(cntO == 3) check[0] = 1;
        if(cntX == 3) check[1] = 1;
    }
    
    int cntX = 0;
    int cntO = 0;
    
    for(int i = 0; i < n; i++){
        if(board[i][i] == 'X')
            cntX++;
        if(board[i][i] == 'O')
            cntO++;
    }
    
    if(cntO == 3) check[0] = 1;
    if(cntX == 3) check[1] = 1;
    
    cntX = 0;
    cntO = 0;
    
    for(int i = 0; i < n; i++){
        if(board[i][n - 1 - i] == 'X')
            cntX++;
        if(board[i][n - 1 - i] == 'O')
            cntO++;
    }
    
    
    if(cntO == 3) check[0] = 1;
    if(cntX == 3) check[1] = 1;

    if(check[0] && check[1])
        return 3;
    else if(check[0])
        return 2;
    else if(check[1])
        return 1;
    
    return 0;
}

int solution(vector<string> board) {
    int answer = 1;
    
    int numO = 0, numX = 0;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == 'O')
                numO++;
            if(board[i][j] == 'X')
                numX++;
        }
    }

    
    
    if(numX > numO) // O -> X
        answer = 0;
    else if(numO > numX + 1) // X -> 0 
        answer = 0;
    else if(chk(board) == 3)
        answer = 0;
    else if(chk(board) == 2 && numO <= numX) // O가 이겼을 때
        answer = 0;
    else if(chk(board) == 1 && numO > numX) // X가 이겼을 때
        answer = 0;

    
    return answer;
}