#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> video;

string go(int N, vector<int>s){
    string ret = "";

    if (N==1){
        return to_string(video[s[0]][s[1]]);
    }

    string LU= go(N/2, {s[0], s[1]});
    string RU= go(N/2, {s[0], s[1]+N/2});
    string LD= go(N/2, {s[0]+N/2, s[1]});
    string RD= go(N/2, {s[0]+N/2, s[1]+N/2});

    if (LU == RU && RU == LD && LD == RD && LU.size()==1){
        ret += LU;
    }
    else{
        ret += "(" + LU + RU + LD + RD + ")";
    }

    return ret;
}

int main(){
    cin >> N;
    video.resize(N, vector<int>(N,0));
    string S;
    for(int i =0 ; i < N ; ++i){
        cin >> S;
        for(int j =0 ; j < N ; ++j){
            video[i][j] = S[j]-'0';
        }
    }


    cout << go(N, {0,0}) << endl;
    return 0;
}