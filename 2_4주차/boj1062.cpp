#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<string> w;
vector<int>visited(26,0);
int mx = -1;

void combi(int start, int r,  vector<char> ret){

    if (ret.size() == r){

        int cnt = 0;
        for(int i = 0 ; i < N ; ++i){

            bool ok = true;
            for(int j = 0 ; j < w[i].size(); ++j){
                if(visited[w[i][j]-'a'] == 0){
                    ok = false;
                    break;
                } 
            }
            if (ok) cnt++;

        }
        if (mx < cnt) mx = cnt;

    }


    for(int i = start+1; i < 26; ++i){

        if (visited[i] == 0){
            visited[i] = 1 ;
            ret.push_back('a'+i);

            combi(i, r, ret);

            visited[i] = 0;
            ret.pop_back();
        }

    }


}

int main(){
    cin >> N >> K;
    w = vector<string>(N);

    for(int i =0 ; i < N ; ++i) cin >> w[i];

    // a n t i c  기본적으로 무조건 있어야 함
    visited['a'-'a'] = 1;
    visited['n'-'a'] = 1;
    visited['t'-'a'] = 1;
    visited['i'-'a'] = 1;
    visited['c'-'a'] = 1;


    if (K < 5) cout << 0;
    else{
        int r = K;
        combi(-1, r, {'a','n','t','i','c'});
        cout << mx ;
    }
    



    return 0;
}