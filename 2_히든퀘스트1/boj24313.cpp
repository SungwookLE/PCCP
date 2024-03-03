#include <bits/stdc++.h>

using namespace std;

int main(){


    int a1, a0;
    cin >> a1 >> a0;

    int c, n0;

    cin >> c >> n0;


    int y = a1*n0+a0;
    int cmp = c*n0;


    while(n0<=100){

        if (y>cmp){
            cout << 0 ;
            return 0;
        }

        n0++;
        y = a1*n0+a0;
        cmp = c*n0;


    }


    cout << 1;
    return 0;


}