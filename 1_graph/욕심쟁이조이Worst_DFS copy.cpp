#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

/*
4
106 93  121 10
61  48  32  9
70  150 11  13
62  38  16  10
*/
int N;
vector<vector<int>> farm;
vector<vector<int>> deltas = {{1,0},{-1,0},{0,1},{0,-1}};


void DFS(int i, int j , vector<vector<int>>& moved, int& moved_n){

    if (moved[i][j] > moved_n)
        moved_n = moved[i][j];

    for(auto d : deltas){
        int next_i = i + d[0];
        int next_j = j + d[1];

        if (next_i >=0 && next_i < N && next_j >=0 && next_j < N){
            if((farm[next_i][next_j] > farm[i][j])){
                moved[next_i][next_j] = moved[i][j]+1;
                DFS(next_i, next_j, moved, moved_n);
            }
        }
    }
}



int main(){

    cin >> N;
    farm = vector<vector<int>>(N, vector<int>(N,0));

    for(int i =0 ; i < N ; ++i){
        for(int j = 0 ; j < N ; ++j){
            cin >> farm[i][j];
        }
    }

    int max_moved = 0;
    cout << "---------------\n";
    for(int i =0 ; i < N ; ++i){
        
        for(int j = 0 ; j < N ; ++j){
            vector<vector<int>> moved(N, vector<int>(N,0));
            int moved_n = 0;
            DFS(i, j, moved, moved_n);

            if ( moved_n > max_moved)
                max_moved = moved_n;
            cout << moved_n << " ";
        }
        cout << endl;
    }

    cout << max_moved << endl;

    return 0;
}