#include <bits/stdc++.h>

using namespace std;

string S;
int main(){
    cin >> S;

    vector<int> v(26,-1);
    for(int i = 0; i < S.size(); ++i){

       if(v[S[i]-'a'] == -1) v[S[i]-'a'] = i;

    }

    for(auto vv: v) cout << vv << " ";





    return 0;
}