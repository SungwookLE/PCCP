#include <bits/stdc++.h>

using namespace std;


int check(int a, int b){


    int ret = 0;
    for(int i = a ; i <= b ; ++i){

        if (i<2) continue;
        else if (i==2) ret++;
        else{
            bool is = true;
            for(int div = 2; div*div <= i ; ++div){
                if(i%div==0){
                    is = false;
                    break;
                } 

            }
            if (is) ret++;
        }

    }

    return ret;    


}


int n;
int main(){


    while(cin >> n){
        if (n==0) break;

        cout << 
        check(n+1, 2*n) << "\n";

    }

    



    return 0;
}