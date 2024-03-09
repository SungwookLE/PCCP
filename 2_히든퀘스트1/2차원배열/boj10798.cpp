#include <bits/stdc++.h>

using namespace std;


vector<string> v;

int main(){


    string s;
    int mx_length = 0;
    for(int i = 0; i < 5 ; ++i){
        cin >> s;
        v.push_back(s);

        if (mx_length < s.size()) mx_length = s.size();
    }


    for(int j = 0 ; j < mx_length; ++j){

        for(int i =0 ; i < 5 ; ++i){


            if( j < v[i].size() ) cout << v[i][j];

        }
    }



    return 0;
}