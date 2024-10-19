#include <bits/stdc++.h>

using namespace std;

int H, W;
vector<vector<char>> sky;
vector<vector<int>> ans;


void simulation(int s){

    for(int i = 0 ; i < H ; ++i){
        for(int j = W-1 ; j > s; --j){
            sky[i][j] = sky[i][j-1];
            sky[i][j-1]='.';

            if (sky[i][j] == 'c' && ans[i][j]==-1){
                ans[i][j] = ans[i][j-1]+1;
            }
        }
    }



    return;
}

int main(){

    cin >> H >> W;
    sky.resize(H, vector<char>(W));
    ans.resize(H, vector<int>(W,-1));

    for(int i =0 ; i < H ; ++i){
        for(int j =0 ; j < W ; ++j){
            cin >> sky[i][j];
            if (sky[i][j]=='c'){
                ans[i][j] = 0;
            }
        }
    }




    for(int i =0 ; i < W; ++i){
        simulation(i);
    }

    for(auto aa: ans){
        for(auto a : aa) cout << a << " ";
        cout << endl;
    }



    return 0;
}