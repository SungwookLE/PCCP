#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> m;
int ans = 30*30;

int main(){
    cin >> N;
    m = vector<vector<int>>(N, vector<int>(N));

    string id;
    for(int i = 0 ; i < N ; ++i){
        string s; cin >> s;
        for(int j = 0 ; j < N ; ++j){
            if (s[j] == 'H'){
                m[i][j] = 0;
            }
            else{ // 뒷면
                m[i][j] = 1;
            } 
        } 
    }

    // 행 뒤집기
    for(int i = 0 ; i < N ; ++i){
        for(int j = 0; j < (1<<N); ++j){


        }
    }

    





    return 0;
}