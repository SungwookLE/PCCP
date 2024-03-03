#include <bits/stdc++.h>

using namespace std;

int M, N;

bool isPrime(int i){

    if (i==1) return false;

    int c = i/2;
    bool ret = true;
    while(c>1){

        if(i%c==0){
            ret = false;
            break;

        }

        c--;
    }
    
    // if(ret) cout << i << " ";

    return ret;
}


int main(){

    cin >> M >> N;

    int sum = 0;
    int mn = N+1;

    for(int i = M ; i <= N ; ++i){
        if (isPrime(i)){
            if (i < mn) mn=i;
            sum += i;
        } 
    }

    if (mn != (N+1)){
        cout << sum << "\n";
        cout << mn;
    }
    else cout << -1 ;

    return 0;
}