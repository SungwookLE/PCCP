#include <bits/stdc++.h>

using namespace std;

int N;

int main(){
    cin >> N;

    for(int i = 1; i <= N; ++i){

        int sum =0 ;
        sum += i;

        int div = i;
        int E = 10;

        while(div>0){
            sum += div%E;
            div = div/E;
        }



        if (sum == N){
            cout << i ;
            return 0;

        }

    }

    cout << 0;



    return 0;
}