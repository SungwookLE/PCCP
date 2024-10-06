#include <bits/stdc++.h>
using namespace std;


string S, cpy;


int main(){
    cin >> S;

    cpy = S;

    reverse(cpy.begin(), cpy.end());

    if (S == cpy){
        cout << 1 ;
    }
    else{
        cout << 0;
    }



    return 0;
}