#include <bits/stdc++.h>

using namespace std;

string S;

bool flag = false;

int main(){
    cin >> S;

    for(int i = 0 ; i < S.size(); ++i){
        if (i < S.size()-1 && S.substr(i,2) == "pi" || S.substr(i, 2) == "ka") i += 1;
        else if(i <S.size()-2 && S.substr(i, 3) == "chu") i +=2;
        else flag = 1;
    }    

    if (flag) cout << "NO";
    else cout << "YES";

    return 0;
}