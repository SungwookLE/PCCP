#include <bits/stdc++.h>

using namespace std;

int N , M;
vector<vector<int>> m;


vector<vector<int>> B = {
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1},
};

vector<vector<int>> W = {
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0},
    {0,1,0,1,0,1,0,1},
    {1,0,1,0,1,0,1,0},
};

int mn = 3000;


int main(){
    cin >> N >> M;
    m = vector<vector<int>>(N, vector<int>(M,-1));

    string s;
    for(int i = 0; i < N ; ++i){
        cin >> s;
        for(int j =0 ; j < M ; ++j){
            if (s[j] == 'W') m[i][j] = 1;
            else m[i][j] = 0;
        }
    }

    for(int i = 0 ; i <= N-8; ++i){
        for(int j =0 ; j <=M-8; ++j){

            int sum_W = 0;
            int sum_B = 0;
            for(int p = i ; p < i+8 ; ++p){
                for(int q = j ; q< j+8 ; ++q){
                    sum_W += abs(m[p][q] - W[p-i][q-j]);
                    sum_B += abs(m[p][q] - B[p-i][q-j]);
                }
            }



            int sum = min(sum_W, sum_B);
            if (sum < mn) mn = sum;


        }
    }


    cout << mn;

    return 0;
}