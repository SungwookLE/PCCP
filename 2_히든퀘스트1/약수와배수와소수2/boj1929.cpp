#include <bits/stdc++.h>

using namespace std;

bool check(int n){


    if (n==1) return false;
    else if (n==2) return true;
    else{


        for(int i = 2 ; i*i <= n ; ++i){
            if (n%i==0) return false;
        }

        return true;
    }
}

int main(){

    int M, N ;
    cin >> M >> N;

    for(int i =M ; i <= N ; ++i){
        if (check(i)) cout << i << "\n";
    }

    return 0;

}