#include <bits/stdc++.h>

using namespace std;


int T;
int main(){
    cin >>T ;

    int C;

    // 25, 10, 5, 1
    vector<vector<int>> rrrr;
    for(int i =0 ; i < T; ++i){
        cin >> C;
        vector<int> ret;


        if ( C / 25){
            ret.push_back(C/25);

            C = C%25;
        }
        else{
            ret.push_back(0);

        }

        if (C / 10){
            ret.push_back(C/10);
            C = C%10;
        }
        else ret.push_back(0);

        if (C / 5){
            ret.push_back(C/5);
            C = C%5;

        }
        else ret.push_back(0);

        ret.push_back(C);
        rrrr.push_back(ret);


    }

    for(auto rr: rrrr){
        for(auto r: rr) cout << r << " ";
        cout << endl;
    }





    return 0;
}