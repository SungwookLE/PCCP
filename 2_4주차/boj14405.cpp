#include <bits/stdc++.h>

using namespace std;

string S;
string m[3] = {"pi", "ka", "chu"};
string comp;

void go(int start, string s){


    for(int i =0 ; i < 3 ; ++i){
        if ( s == m[i] ){
            comp += s;
            s = "";
        }
    }

    if (start == S.size()) return;


    s += S[start];
    go(start+1, s);


    return;
}

int main(){

    cin >> S;


    go(0, "");

    if (comp == S) cout << "YES";
    else cout << "NO";

    return 0;
}