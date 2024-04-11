#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<vector<int>> B;
vector<vector<vector<int>>> B_STACK;
vector<tuple<int, int, int>> C;
map<int, char> mp;


void moving(int idx, int d){
    // d => 1: right, 2: left, 3: up, 4: down

    int& r = get<0>(C[idx]);
    int& c = get<1>(C[idx]);

    if (d==1) c += 1;
    else if (d==2) c-=1;
    else if (d==3) r-=1;
    else r+=1;

    return;
}

void debug(int turn){

    mp[1] = '>';
    mp[2] = '<';
    mp[3] = '^';
    mp[4] = 'v';

    cout << "DEBUG(" << turn << ")\n";
    for(auto bbb: B_STACK){
        for(auto bb : bbb){
            cout << "{" ;
            for(auto b : bb){
                cout << b+1 << mp[get<2>(C[b])] << ",";
            }
            cout << "\t}";
        }
        cout << endl;
    }
}

int main(){
    
 

    cin >> N >> K;
    B = vector<vector<int>>(N, vector<int>(N+10,0));
    B_STACK= vector<vector<vector<int>>>(N+10, vector<vector<int>>(N+10));

    C = vector<tuple<int, int, int>>(K);

    for(int i = 0; i < N ; ++i){
        for(int j = 0 ;j < N ; ++j)
            cin >> B[i][j];
    } // 0: 흰색, 1: 빨강, 2: 파랑

    int a1, b1, c1;
    for(int i = 0; i < K ; ++i){
        cin >> a1 >> b1 >> c1;
        get<0>(C[i]) =a1-1;
        get<1>(C[i]) =b1-1;
        get<2>(C[i]) = c1;
        B_STACK[get<0>(C[i])][get<1>(C[i])].push_back(i);
    }// 1: right , 2: left, 3: up, 4: down


    int turn = 0;
    while (turn < 1000){
        turn++;

        for(int i = 0 ; i < K ; ++i){
            int r_now = get<0>(C[i]);
            int c_now = get<1>(C[i]);

            vector<int> v;
            auto it = find(B_STACK[r_now][c_now].begin(), B_STACK[r_now][c_now].end(), i);
            
            while(it != B_STACK[r_now][c_now].end()){
                v.push_back(*it);
                it++;
            }

            B_STACK[r_now][c_now].erase(find(B_STACK[r_now][c_now].begin(), B_STACK[r_now][c_now].end(), i), B_STACK[r_now][c_now].end());

            int& d = get<2>(C[v.front()]);
            moving(v.front(), d);

            int r = get<0>(C[v.front()]);
            int c = get<1>(C[v.front()]);

            bool isDouble1 = false;
            if (r < 0){
                r = 1;
                d = 4;
                if (B[r][c] == 2){
                    r = 0;
                    isDouble1 = true;
                }
            }
            else if (r >= N){
                r = N-2;
                d = 3;
                if (B[r][c] == 2){
                    r = N-1;
                    isDouble1 = true;
                }
            }
            else if (c < 0){
                c = 1;
                d = 1;
                if (B[r][c] == 2){
                    c = 0;
                    isDouble1 = true;
                }
            }
            else if (c >= N){
                c = N-2;
                d = 2;
                if (B[r][c] == 2){
                    c = N-1;
                    isDouble1 = true;
                }
            }

            int color = B[r][c];
            if (color == 0 || color == 1){
                if (color == 1  && !isDouble1) reverse(v.begin(), v.end());
                for(auto vv : v){
                    get<0>(C[vv]) = r;
                    get<1>(C[vv]) = c;
                    B_STACK[r][c].push_back(vv);
                }
            }
            else if (color == 2){
                bool isDouble2 = false;
                if ( d == 1){
                    c -= 2;
                    d = 2;
                    if ( c < 0){ 
                        c = 0;
                        isDouble2 = true;
                    }
                    if (B[r][c] == 2){
                        c+=1;
                        isDouble2 = true;
                    }
                }
                else if ( d== 2){
                    c += 2;
                    d = 1;
                    if ( c >= N){ 
                        c = N-1;
                        isDouble2 = true;
                    }
                    if (B[r][c] == 2){
                        c-=1;
                        isDouble2 = true;
                    }
                }
                else if ( d== 3){
                    r += 2;
                    d = 4;
                    if ( r >= N){
                        r = N-1;
                        isDouble2 = true;
                    }
                    if (B[r][c] == 2){
                        r-=1;
                        isDouble2 = true;
                    }
                }
                else if (d == 4){
                    r -= 2;
                    d = 3;
                    if ( r < 0){
                        r = 0;
                        isDouble2 = true;
                    } 
                    if (B[r][c] == 2){
                        isDouble2 = true;
                        r+=1;
                    }
                }

                if (B[r][c] == 1 && !isDouble2) reverse(v.begin(), v.end());
                for(auto vv : v){
                    get<0>(C[vv]) = r;
                    get<1>(C[vv]) = c;
                    B_STACK[r][c].push_back(vv);
                }
            }
            // debug(turn);

            if (B_STACK[r][c].size() >= 4){
                cout << turn;
                return 0;
            }
        }
    }

    cout << -1;
    return 0;
}