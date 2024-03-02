#include <bits/stdc++.h>

using namespace std;

int N;
int B;

int main(){

    cin >> N >> B;

    vector<int> v;
    while(N>=B){


        v.push_back(N%B);
        N = N/B;

    }

    if (N!=0) v.push_back(N);



    reverse(v.begin(), v.end());
    for(auto vv: v){
        
        if (vv>=10) cout << char(vv-10+'A');
        else cout << vv;
        
    }


    return 0;
}