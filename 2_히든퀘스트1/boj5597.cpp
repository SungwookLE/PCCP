#include <bits/stdc++.h>

using namespace std;

int s[31]={0,};

int main(){


    int n;
    for(int i = 0; i < 28 ; ++i){
        cin >> n;
        s[n] = 1;

    }

    for(int i = 1 ; i <= 30; ++i){
        if(s[i]==0) cout << i << endl;
    }



    return 0;
}