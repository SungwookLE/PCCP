#include <bits/stdc++.h>
using namespace std;

int main(){


    int n ;
    cin >> n;

    string mid = "*";
    for(int i = 1 ; i < n ; ++i){
        mid+="**";
    }


    for(int i = 0 ; i < (n-1)+1 ; ++i){

        for(int j = i ; j < n-1; ++j){
            cout << " ";
        }

        for(int j = 0 ; j < (i+1)*2-1; ++j) cout <<"*";
        cout << endl;

    }

     for(int i = 0 ; i < (n-1) ; ++i){

        for(int j = 0 ; j < i+1; ++j){
            cout << " ";
        }

        for(int j = 0 ; j < 2*n-(i+1)*2-1; ++j) cout <<"*";
        cout << endl;

    }



    return 0;
}