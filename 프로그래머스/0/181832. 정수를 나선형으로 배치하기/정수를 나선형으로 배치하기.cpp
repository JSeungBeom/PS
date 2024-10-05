#include <bits/stdc++.h>

using namespace std;

int arr[35][35];

tuple<int, int, int> ri(int x, int y, int st, int n){
    while(y < n && !arr[x][y]){
        arr[x][y++] = st++;
    }
    
    return {x + 1, y - 1, st};
}

tuple<int, int, int> le(int x, int y, int st, int n){
    while(y >= 0 && !arr[x][y]){
        arr[x][y--] = st++;
    }
    
    return {x - 1, y + 1, st};
}

tuple<int, int, int> up(int x, int y, int st, int n){
    while(x >= 0 && !arr[x][y]){
        arr[x--][y] = st++;
    }
    
    return {x + 1, y + 1, st};
}

tuple<int, int, int> down(int x, int y, int st, int n){
    while(x < n && !arr[x][y]){
        arr[x++][y] = st++;
    }
    
    return {x - 1, y - 1, st};
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    
    int st = 1;
    int x = 0;
    int y =0;
    
    while(true){
        tie(x, y, st) = ri(x, y, st, n);
        cout << x << ' ' << y << ' ' << st << '\n';
        if(st > n * n) break;
        tie(x, y, st) = down(x, y, st, n);
        if(st > n * n) break;
        tie(x, y, st) = le(x, y, st, n);
        if(st > n * n) break;
        tie(x, y, st) = up(x, y, st, n);
        if(st > n * n) break;
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            answer[i][j] = arr[i][j];
        }
    }
    
    return answer;
}