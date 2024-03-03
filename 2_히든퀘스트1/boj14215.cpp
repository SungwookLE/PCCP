#include <bits/stdc++.h>

using namespace std;

int a, b, c;

int main(){

    cin >> a >> b >> c;

    if ( a < b){
        int temp = a;
        a = b;
        b = temp;
    }

    if (a < c){
        int temp = a;
        a = c;
        c = temp;
    }

    if ( b< c){
        int temp = b;
        b = c;
        c = temp;
    }

    if ( a < (b+c)){

        cout << a+b+c;
    }
    else{

        a = b+c-1;
        cout << a+b+c;


    }




    return 0;
}