#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<long long>> B;
vector<vector<int>> delta = {{-1,0},{1,0},{0,-1}, {0,1}};
long long ans = 0;

long long findMax(vector<vector<long long>>& B2){

    long long mx = 0;
    for(int i =0 ; i < N ; ++i){
        for(int j =0 ; j < N ; ++j){
            if (mx < B2[i][j]){
                mx = B2[i][j];
            }
        }
    }

    return mx;
}


void dfs(int cnt, vector<vector<long long>> B2, char d){


    // cout << cnt << "(" << d << ")" << ": " << endl;
    // for(auto b2: B2){
    //     for(auto bb: b2) cout << bb << " ";
    //     cout << endl;
    // }
    // cout << endl;   
    
    if (cnt == 5){
   
        long long ret = findMax(B2);
        if (ans < ret){
            ans = ret;
        }
        return;
    }
    vector<vector<long long>> tempB = B2;

    // 위로
    for(int j =0 ; j < N ; ++j){
        int s = 0, e = 1; 
        while (e < N){

            if (tempB[s][j] == tempB[e][j]){
                B2[s][j] += B2[e][j];
                B2[e][j] = 0;
                s = e+1;
                e = s+1;
            }
            else if (tempB[e][j] != 0){
                s++;
                e = s+1;
            }
            else{
                e++;
            }
        }

        s = 0, e= 0;
        while ( e < N){
            if (B2[e][j] == 0)
                e++;
            else{
                if (s!= e){
                    B2[s][j] = B2[e][j];
                    B2[e][j] = 0;
                }
                s++;
                e = s;
            }
        }
    }
    dfs(cnt+1, B2, '^');
    B2 = tempB;

    // 아래로
    for(int j =0 ; j < N ; ++j){
        int s = N-1;
        int e = s-1; 
        while (e >= 0){

            if (tempB[s][j] == tempB[e][j]){
                B2[s][j] += B2[e][j];
                B2[e][j] = 0;
                s = e-1;
                e = s-1;
            }
            else if (tempB[e][j] != 0){
                s--;
                e = s-1;
            }
            else{
                e--;
            }
        }

        s = N-1, e= N-1;
        while ( e >= 0){
            if (B2[e][j] == 0)
                e--;
            else{
                if (s!= e){
                    B2[s][j] = B2[e][j];
                    B2[e][j] = 0;
                }
                s--;
                e = s;
            }
        }

    }
    dfs(cnt+1, B2, 'v');
    B2 = tempB;

    // 왼쪽으로
    for(int i =0 ; i < N ; ++i){
        int s = 0, e = 1; 
        while (e < N){

            if (tempB[i][s] == tempB[i][e]){
                B2[i][s] += B2[i][e];
                B2[i][e] = 0;
                s = e+1;
                e = s+1;
            }
            else if (tempB[i][e] != 0){
                s++;
                e = s+1;
            }
            else{
                e++;
            }
        }

        s = 0, e= 0;
        while ( e < N){
            if (B2[i][e] == 0)
                e++;
            else{
                if (s!= e){
                    B2[i][s] = B2[i][e];
                    B2[i][e] = 0;
                }   
                s++;
                e = s;
            }
        }

    }
    dfs(cnt+1, B2, '<');
    B2 = tempB;

    // 오른쪽
    for(int i =0 ; i < N ; ++i){
        int s = N-1;
        int e = s-1; 
        while (e >= 0){

            if (tempB[i][s] == tempB[i][e]){
                B2[i][s] += B2[i][e];
                B2[i][e] = 0;
                s = e-1;
                e = s-1;
            }
            else if (tempB[i][e] != 0){
                s--;
                e = s-1;
            }
            else{
                e--;
            }
        }

        s = N-1, e= N-1;
        while ( e >= 0){
            if (B2[i][e] == 0)
                e--;
            else{
                if (s!= e){
                    B2[i][s] = B2[i][e];
                    B2[i][e] = 0;
                } 
                s--;
                e = s;
            }
        }
    }
    dfs(cnt+1, B2, '>');
    B2 = tempB;

    
    return;


}

int main(){
    cin >> N;
    B = vector<vector<long long>>(N, vector<long long>(N,0));
    
    for(int i =0 ; i < N ; ++i){
        for(int j =0 ; j < N ; ++j)
            cin >> B[i][j];
    }

    dfs(0, B, ' ');
    cout << ans;


    return 0;
}