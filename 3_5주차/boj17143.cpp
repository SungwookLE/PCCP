#include <bits/stdc++.h>

using namespace std;

int R, C, M;
vector<vector<tuple<int, int, int>>> B;


void moveShark(vector<vector<tuple<int, int, int>>>& B){

    vector<vector<tuple<int, int, int>>> tempB = B;
    vector<vector<int>> visited(R+1, vector<int>(C+1,0));

    for(int i = 1 ; i <= R; ++i){
        for(int j = 1; j <= C; ++j){
            int speed = get<0>(B[i][j]);
            int delta = get<1>(B[i][j]); // d:up(1), d:down(2), d:right(3), d:left(4)
            int size  = get<2>(B[i][j]);

            if (size != 0){
                if (visited[i][j] == 0) tempB[i][j] = {0,0,0}; 

                if (delta == 1){
                    int s = i;
                    int mov = -1;
                    int sd = speed;

                    while(sd > 0){
                        if ((s+mov >= 1) && (s+mov <= R)) s = s+mov;
                        else{ s = s-mov, mov *= -1;}
                        if ((s == 1) || (s == R)) mov *= -1;
                        sd--;
                    }           

                    if (visited[s][j] == 0 ||get<2>(tempB[s][j]) < size){
                        if (mov == -1) tempB[s][j] = {speed, 1, size}; 
                        else tempB[s][j] = {speed, 2, size};

                        visited[s][j] = 1;
                    }
                }

                else if (delta == 2){
                    int s = i;
                    int mov = 1;
                    int sd = speed;

                    while(sd>0){
                        if ((s+mov >= 1) && (s+mov <= R)) s = s+mov; 
                        else s = s-mov, mov *= -1;

                        if ((s == 1) || (s == R)) mov *= -1;
                        sd--;
                    }

                    if (visited[s][j] == 0 ||  get<2>(tempB[s][j]) < size){
                        if (mov == -1) tempB[s][j] = {speed, 1, size}; 
                        else tempB[s][j] = {speed, 2, size};

                        visited[s][j] = 1;
                    }
                }

                else if (delta == 3){
                    int s = j;
                    int mov = 1;
                    int sd = speed;

                    while(sd>0){
                        if ((s+mov >= 1) && (s+mov <= C)) s = s+mov; 
                        else s = s-mov, mov *= -1;
                        
                        if ((s == 1) || (s == C)) mov *= -1;

                        sd--;
                    }
                    if (visited[i][s] == 0 || get<2>(tempB[i][s]) < size){
                        if (mov == -1) tempB[i][s] = {speed, 4, size}; 
                        else tempB[i][s] = {speed, 3, size};

                        visited[i][s] = 1;
                    }
                }

                else if (delta == 4){
                    int s = j;
                    int mov = -1;
                    int sd = speed;

                    while(sd>0){
                        if ((s+mov >= 1) && (s+mov <= C)) s = s+mov; 
                        else s = s-mov, mov *= -1;

                        if ((s == 1) || (s == C)) mov *= -1;

                        sd--;
                    }
                    if (visited[i][s] == 0 || get<2>(tempB[i][s]) < size){
                        if (mov == -1) tempB[i][s] = {speed, 4, size}; 
                        else tempB[i][s] = {speed, 3, size};

                        visited[i][s] = 1;
                    }
                }
            }
        }

    }


    B = tempB;
}


int fishShark(vector<vector<tuple<int, int, int>>>& B, int c){

    int size = 0;
    for(int i = 1; i <= R; ++i){
        size = get<2>(B[i][c]);
        if (size != 0){
            B[i][c] = {0,0,0};
            break;
        }
    }

    return size;
}

void debug(){
    for(int i = 1; i <= R ; ++i){
        for(int j = 1; j <= C ; ++j){
            cout << get<0>(B[i][j]) << "," << get<1>(B[i][j]) << "," << get<2>(B[i][j]) << "\t" ;
        }
        cout << endl;
    }

}

int main(){
    // 낚시왕이 오른쪽으로 한 칸 이동
    // 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 상어는 사라진다.
    // 상어가 이동
        // 상어는 주어진 속도로 이동하고, 상어가 이동하려는 칸이 격자판의 경계를 넘는 경우 방향을 바꿔서 이동한다.
        // 상어 이동 후, 한 칸에 상어가 두마리 이상잇으면, 크기가 큰놈만 남는다.
    // 낚시왕이 잡은 상어 크기의 합을 구해보자

    cin >> R >> C >> M;
    B = vector<vector<tuple<int, int, int>>>(R+1, vector<tuple<int, int, int>>(C+1, {0,0,0}));

    int r, c, s, d, z;
    for(int i =0 ; i < M ; ++i){
        cin >> r >> c >> s >> d >> z;
        B[r][c] = {s, d, z};
    }
    long long ret = 0;
    for(int i = 1; i <= C ; ++i){
        // cout << i << "th" << endl;
        // debug();
        ret+=fishShark(B, i);
        // cout << "SZ: " << ret << endl;

        moveShark(B);
    }

    cout << ret;


    return 0;
}