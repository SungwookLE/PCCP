#include <bits/stdc++.h>

using namespace std;

int v[9][9];

int mx= 0;
pair<int, int> place;
int main(){
    for(int i = 0; i < 9;++i){
        for(int j =0 ; j <9 ; ++j){
            cin >> v[i][j];

            if ( mx < v[i][j]){
                mx = v[i][j];
                place = {i,j};
            }
        }
    }
    
    cout << mx << endl << place.first+1 << " "<< place.second+1;




    return 0;
}