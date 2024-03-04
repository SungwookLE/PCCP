#include <bits/stdc++.h>

using namespace std;

int N, M;

int main(){

    cin >> N >> M;

    map<string, int> m;
    string s;
    for(int i =0 ; i < N ;++i){
        cin >> s;
        m[s] += 1;
    }

    int ans =0;
    vector<string> ret;
    for(int i =0 ; i < M ;++i){
        cin >> s;
        if (m.count(s)){
            ans +=1 ;
            ret.push_back(s);
        }

    }

    sort(ret.begin(), ret.end());
    cout << ans << "\n";
    for(auto r : ret) cout << r << "\n";




    return 0;
}