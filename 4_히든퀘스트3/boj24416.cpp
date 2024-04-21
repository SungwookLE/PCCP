#include <bits/stdc++.h>

using namespace std;

int N ;
int cnt=0;

int fib(int n){

    if (n ==1 || n == 2){
        cnt++;
        return 1;
    }
    else{
        return (fib(n-1) + fib(n-2));
    }
}


int fibonacci(int n){

    int F[41] = {0,};
    F[1] = F[2] = 1;
    for(int i = 3; i <= n; ++i){
        F[i] = F[i-1]+F[i-2];
    }

    return F[n];
}


int main(){
    cin >> N;

    fib(N);

    cout << cnt << " " << N-2 << endl;



    return 0;
}