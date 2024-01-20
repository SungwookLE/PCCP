#include <bits/stdc++.h>

using namespace std;


int n, k;
vector<int> V;


void combi(int start, vector<int> ret){

    if (ret.size() == k){
        for(auto r : ret)
            cout << r << " ";
        cout << endl;
    }

    for(int i = start+1; i < n; ++i){
        ret.push_back(i);
        combi(i, ret);
        ret.pop_back();
    }
}


int main(){

    cin >> n >> k;
    V = vector<int>(n,0);

    for(int i = 0 ; i < n ; ++i)
        cin >> V[i];

    vector<int> ret;
    combi(-1, ret);

    return EXIT_SUCCESS;
}