#include <bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin >> s;
    
    sort(s.begin(), s.end());
    do{
        string temp = s;
        reverse(temp.begin(), temp.end());
        if( s == temp){
            cout << s ;
            return 0;
        }
    }while (next_permutation(s.begin(), s.end()));


    cout << "I'm Sorry Hansoo";

    return 0;
}