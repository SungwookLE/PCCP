#include <bits/stdc++.h>

using namespace std;

int T;

int gcd(int a, int b){ // greates common divisor 최대공약수

    if (a<b){
        int temp;
        temp = a;
        a = b;
        b = temp;
    }

    while(a%b){

        int mod = a%b;

        a= b;
        b = mod;

        // a=10, b=6 -> mod = 4 -> a=6, b=4
        // mod = 2 -> a=4, b=2
        // mod = 0 -> a=2, b=0

    }


    return b;

}

int lcm(int a, int b){ // least common multiplier 최소공배수

    return a*b/gcd(a,b);
}


int main(){
    cin >> T;

    int A, B;
    for(int i = 0 ; i < T; ++i){
        cin >> A >> B;
        cout << lcm(A,B) << endl;



    }


    return 0;
}