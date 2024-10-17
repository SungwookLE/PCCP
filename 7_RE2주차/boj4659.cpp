#include <bits/stdc++.h>

using namespace std;
string s;
int moum[26];

bool check(string S, int idx, bool isMoum){

    if (moum[s[idx]-'a']==1){
        isMoum = true;
    }

    if (s==S){
        if (isMoum) return true;
        else return false;
    }

    
    if (idx == 0){
        S += s[idx];
    }
    else if (idx > 0){

        if(S[idx-1] == s[idx]){
            if (s[idx] != 'e' && s[idx] !='o' ){
                return false;
            }
        }

        if (idx>1){
            int cmp1 = moum[s[idx]-'a'];
            int cmp2 = moum[S[idx-1]-'a'];
            int cmp3 = moum[S[idx-2]-'a'];
            if (cmp1 == cmp2 && cmp2 == cmp3){
                return false;
            }
        }

        S += s[idx];
    }

    return check(S, idx+1, isMoum);
}


int main(){
    moum['a'-'a'] = 1;
    moum['e'-'a'] = 1;
    moum['i'-'a'] = 1;
    moum['o'-'a'] = 1;
    moum['u'-'a'] = 1;


    while(cin >> s){
        if (s=="end") break;

        if(check("", 0, false)){
            cout << "<" << s << "> " << "is acceptable." << endl;
        }    
        else{
            cout << "<" << s << "> " << "is not acceptable." << endl;
        }


    }

    return 0;
}
