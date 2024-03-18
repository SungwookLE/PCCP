#include <bits/stdc++.h>

using namespace std;

int N;
vector<vector<int>> cnr;

void debug(){
    for(auto cc: cnr){
        for(auto c : cc) cout << c << " ";
        cout << endl;
    }
    cout << endl;
}

void rot90(vector<pair<int, int>>& pnt_set){

    auto e1 = pnt_set.end()-1;

    int diff_i = e1->first;
    int diff_j = e1->second;

    int sz = pnt_set.size();
    for(int i = sz-2 ; i >= 0; --i){
        int row = pnt_set[i].first;
        int col = pnt_set[i].second;

        row -= diff_i;
        col -= diff_j;

        int temp = row;
        row = col;
        col = -temp;

        row += diff_i;
        col += diff_j;

        cnr[row][col] = 1;
        pnt_set.push_back({row,col});
    }

}

int check_square(){
    int ret = 0;

    for(int i = 1 ; i <cnr.size(); ++i){
        for(int j =1 ; j < cnr[0].size(); ++j){

            if (cnr[i][j] == 1){
                if (cnr[i-1][j] == 1){
                    if (cnr[i][j-1] == 1){
                        if (cnr[i-1][j-1] == 1) ret++;
                    }
                }
            }
        }
    }
    return ret;
}


int main(){
    cin >> N;
    cnr = vector<vector<int>>(101, vector<int>(101,0));

    int j, i, d, g; // (i,j): 드래곤 커브의 시작점, d: 시작 방향, g: 세대
    for(int n =0 ; n < N ; ++n){
        vector<pair<int, int>> pnt_set;

        cin >> j >> i >> d >> g;
        cnr[i][j] = 1;
        pnt_set.push_back({i,j});

        if (d==0){
            cnr[i][j+1] = 1;
            pnt_set.push_back({i,j+1});
        }
        else if (d==1){
            cnr[i-1][j] = 1;
            pnt_set.push_back({i-1,j});
        }
        else if (d==2){
            cnr[i][j-1] = 1;
            pnt_set.push_back({i,j-1});
        }
        else if (d==3){
            cnr[i+1][j] = 1;
            pnt_set.push_back({i+1,j});
        }

        while(g>=1){
            rot90(pnt_set);
            g--;
        }
    }

    cout << check_square();


    return 0;
}