#include <bits/stdc++.h>

using namespace std;


int N, K;
vector<vector<int>> B;
vector<vector<vector<int>>> B_STACK;
vector<tuple<int, int, int>> C;

void moveDir(int& r, int& c, int dir){
    // 1: right , 2: left, 3: up, 4: down

    if (dir == 1){
        c += 1;
        if (B[r][c] == 2) c-=1;

    }
    else if (dir == 2){
        c-=1;
    
    }
    else if (dir ==3){
        r-=1;
    
    } 
    else if (dir ==4){
        r+=1;
    
    }
    
    
    return;
}

bool move_unit(int&r, int&c, int& dir){
    // 경계를 벗어난 경우 false

    moveDir(r,c,dir);


    if (c < 0){
        c= 0;
        dir = 1;
        return false;
    }

    else if (c >= N){
        c = N-1;
        dir = 2;
        return false;
    }
    
    if (r < 0){
        r = 0;
        dir = 4;
        return false;
    }

    else if (r >= N){
        r = N-1;
        dir = 3;
        return false;
    }

    return true;
}

void moveRed_unit(tuple<int, int, int>& horse){

    move_unit(horse);
    return;
}

void moveWhite(int idx){

    int  r   = get<0>(C[idx]);
    int  c   = get<1>(C[idx]);
    int  dir = get<2>(C[idx]);


    vector<int> horses = B_STACK[r][c];

    for(int i = horses.size()-1; i >=0 ; --i){

        move_unit(C[horses[i]]);
        B_STACK.pop_back();
        B_STACK[get<0>(C[horses[i]])][get<1>(C[horses[i]])].push_back(horses[i]);

        if (i == idx) break;
    }
}








int main(){

    cin >> N >> K;
    B = vector<vector<int>>(N, vector<int>(N,0));
    B_STACK= vector<vector<vector<int>>>(N, vector<vector<int>>(N));

    C = vector<tuple<int, int, int>>(K);

    for(int i = 0; i < N ; ++i){
        for(int j = 0 ;j < N ; ++j)
            cin >> B[i][j];
    } // 0: 흰색, 1: 빨강, 2: 파랑


    for(int i = 0; i < K ; ++i){
        cin >> get<0>(C[i]) >> get<1>(C[i]) >> get<2>(C[i]);
        B_STACK[get<0>(C[i])][get<1>(C[i])].push_back(i);
    }// 1: right , 2: left, 3: up, 4: down


    int turn = 0;
    while (turn < 1000){
        turn++;


        


    }

    cout << -1;
    return 0;
}