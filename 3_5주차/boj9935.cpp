#include <bits/stdc++.h>

using namespace std;

string S, d;
string temp;
int main(){
    cin >> S;
    cin >> d;


    for(int i = 0; i < S.size(); ++i){
        temp += S[i];
        if (temp.size()>=d.size())
            if( temp.substr(temp.size()-d.size(), d.size()) == d ){
                temp.erase(temp.end()-d.size(), temp.end());
            }
        
    }

    if (temp.size()) cout << temp ;
    else cout << "FRULA";



    return 0;
}