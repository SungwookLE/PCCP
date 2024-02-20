#include <bits/stdc++.h>
using namespace std;

int N;
int mp, mf, ms, mv;

vector<vector<int>> m;

int main(){

    cin >> N ; 
    cin >> mp >> mf >> ms >> mv;

    m = vector<vector<int>>(N, vector<int>(5,0));

    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < 5 ; ++j){
            cin >> m[i][j];
        }
    }


    /*
    0000000
    0000001
    0000010
    0000011
    0000100
    0000101
    0000110
    0000111
    ...
    0111111
    */
    int min_C = 500*200;
    int ans =-1;

    for(int i = 0 ; i < (1<<N); ++i){

        int sum_p = 0, sum_f = 0, sum_s = 0, sum_v = 0, sum_c = 0;

        for(int j = 0 ; j < N ; ++j){
            
            if (i & (1<<j)){
                sum_p+= m[j][0];
                sum_f+= m[j][1];
                sum_s+= m[j][2];
                sum_v+= m[j][3];
                sum_c+= m[j][4];
            }
        }


        if (sum_p >= mp && sum_f >= mf && sum_s >= ms && sum_v >= mv){
            
            if (min_C > sum_c){
                min_C = sum_c;
                ans = i ;
            }
            else if (min_C == sum_c){
                // 이거 어떻게 해야 사전순 정렬이되지? ㅎㅎ;;                
                
            }
        }
    }

    if (ans == -1)
        cout << -1 ;
    else{
        cout << min_C << "\n";
        for(int j = 0 ; j < N ;++j){
            if( ans & (1<<j)){
                cout << j+1 << " ";
            }
        } // 1 2 3
        
    }
    return 0;
}