#include <bits/stdc++.h>

using namespace std;

int A;

int MODs[42] = {0,};

int main(){

    int A ;
    for(int i = 0; i < 10 ; ++i){
        cin >> A;

        int mod = A%42;
        MODs[mod] += 1;
    }

    int ret = 0;
    for(int i = 0; i < 42 ; ++i){

        if (MODs[i] > 0) ret++;
    }

    cout << ret;


    return 0;
}