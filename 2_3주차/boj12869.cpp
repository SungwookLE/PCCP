#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> SCV;
vector<vector<int>> attack = {{9,3,1}, {9,1,3}, {3,9,1}, {3,1,9}, {1,9,3}, {1,3,9}};
queue<vector<int>> candidates;

int main(){
    cin >> N;
    SCV = vector<int>(3,0);

    for(int i = 0 ; i < N ; ++i) cin >> SCV[i];

    SCV.push_back(0);
    candidates.push(SCV);

    while(!candidates.empty()){


        vector<int> now = candidates.front();
        candidates.pop();

        bool ret = true;
        cout << now[3] << ": " ;
        for(int i = 0 ; i < 3 ; ++i){
            cout << now[i] << " ";
            if (now[i]>0) ret= false;
        }
        cout << endl;

        if (ret){
            cout << now[3];
            break;
        }


        for(auto at : attack){
            vector<int> tmp;
            for(int i = 0 ; i < 3 ; ++i)
                tmp.push_back(now[i] - at[i]);
            tmp.push_back(now[3]+1);
            candidates.push(tmp);
        }


    }






    return 0;
}