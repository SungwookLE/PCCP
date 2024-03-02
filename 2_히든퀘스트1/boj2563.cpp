#include <bits/stdc++.h>

using namespace std;


int N;
vector<vector<int>> al(101, vector<int>(101,0));
int main(){
    cin >> N;

    int ret =0;
    int p, q;
    for(int i =0 ; i < N ; ++i){
        cin >> p >> q;



        for(int k = q+1; k <= (q+10); ++k){
            for(int j = p+1 ; j <= (p+10); ++j){
                
                
                if (al[k][j] == 0){ al[k][j] = 1;
                    ret+=1;
                }

            }
        }


    }

    cout << ret ;








    return 0;
}